#使用llvm实现一门语言 —— cava 


###背景

cava 产生的背景，是由于ha3业务方对插件定制及版本兼容需求，要求我们基于llvm开发一种性能与c++相当的类java脚本语言。
经过我们的调查发现：

可备选项由例如sp上的lua，elasticsearch上的groovy等，但最终得出的结论是现有的脚本语言都不能很好的满足ha3的需求。

groovy是jvm语言，它和用java开发的elasticsearch比较配。ha3是用c++开发的，ha3上插件的内存管理模式很固定，插件中的内存分配可以和请求session的pool绑定，请求结束整个pool释放，不需引入gc；另外jni比较重和c++交互的效率不高，因jvm语言不满足要求。

公认和c++结合比较好的是lua，它在游戏领域被广泛使用，lua本身比较轻量，它通过lua栈和c++交互，lua有个非官方版的jit实现luajit，不考虑和c++交互的话，luajit的性能非常不错。但是在ha3算分过滤等场景，脚本和c++交互的次数能达到百万级别，c++交互上的开销是一个不能忽略的因素，lua在这种场景性能还是满足不了我们的要求。

最终，我们决定自己实现一门类java脚本语言——cava。

本文将分享下如何使用 LLVM 来实现一门语言，以cava作为例子来具体讲述编译器各个阶段的实现：
编译器经典流程

编译器通过词法分析 -> 语法分析 -> 语义分析 -> 中间代码优化 -> 目标代码生成，最终生成汇编指令，再由汇编语言根据不同的指令集生成对应的可执行程序

cava使用Bison和flex来实现词法语法分析，使用llvm来实现中间代码到编译执行
词法 & 语法

基于 Bison 和 flex 实现词法语法分析器

```c++
token

token定义

%token BOOLEAN // primitive_type
%token CHAR BYTE SHORT INT LONG UBYTE USHORT UINT ULONG // integral_type
%token DOUBLE FLOAT // floating_point_type
%token NULL_LITERAL
%token LBRACK RBRACK // array_type
%token DOT // qualified_name
%token SEMICOLON MULT COMMA LBRACE RBRACE EQ // separators
%token LPAREN RPAREN COLON // more separators
...
token识别，使用flex

"(" { updateLocation(yylloc, YYLeng()); return token::LPAREN;    }
")" { updateLocation(yylloc, YYLeng()); return token::RPAREN;    }
"{" { updateLocation(yylloc, YYLeng()); return token::LBRACE;    }
"}" { updateLocation(yylloc, YYLeng()); return token::RBRACE;    }
"[" { updateLocation(yylloc, YYLeng()); return token::LBRACK;    }
"]" { updateLocation(yylloc, YYLeng()); return token::RBRACK;    }
token_type boolLiteral(semantic_type *yylval, location_type *yylloc, bool val) {
    updateLocation(yylloc, YYLeng());
    yylval->booleanLiteral = val;
    return token::BOOLEAN_LITERAL;
}
token_type intLiteral(semantic_type *yylval, location_type *yylloc) {
    yylval->integerLiteral = atoi(YYText());
    updateLocation(yylloc, YYLeng());
    return token::INTEGER_LITERAL;
}
...
```
位置信息

cava在词法分析阶段就透出了位置信息，记录下了所有token所在文件的行列号，用于后续报错处理时能够准确的定位错误位置

```C
void updateLocation(location_type *yylloc, int width) {
    updateBegin(yylloc, 0);
    updateEnd(yylloc, width);
}
```

语法 parser

利用Bison定义语法规则，维护token之间的排列关系
```c
expression : assignment_expression {
    @$ = @1;
    $$ = $1;
}

assignment_expression : conditional_expression {
    @$ = @1;
    $$ = $1;
}
| assignment { $$ = $1; }

conditional_expression : conditional_or_expression {
    @$ = @1;
    $$ = $1;
}
| conditional_or_expression QUESTION expression COLON conditional_expression {
    @$ = @1 + @2 + @3 + @4 + @5;
    $$ = NodeFactory::createConditionalExpr(ctx, @$, $1, $3, $5);
}

conditional_or_expression : conditional_and_expression {
    @$ = @1;
    $$ = $1;
}
| conditional_or_expression OROR conditional_and_expression {
    @$ = @1 + @2 + @3;
    $$ = NodeFactory::createBinaryOpExpr(ctx, @$, $1, BinaryOpExpr::OT_COND_OR, $3);
}

conditional_and_expression : inclusive_or_expression {
    @$ = @1;
    $$ = $1;
}
| conditional_and_expression ANDAND inclusive_or_expression {
    @$ = @1 + @2 + @3;
    $$ = NodeFactory::createBinaryOpExpr(ctx, @$, $1, BinaryOpExpr::OT_COND_AND, $3);
}
```
AST
AST 生成

在语法分析的时候，cava利用NodeFactory类生成对应的AST，把token连接成语法树

AST设计参考

以上文中 BinaryOpExpr 为例， binaryOpExpr 表示二元表达式。先创建对应的BinaryOpExpr 类，继承Expr类，里面包含成员左表达式 _left，右表达式 _right, 以及 表达式类型 _op。
```c++
class BinaryOpExpr : public Expr
{
public:
      enum OpType {
        // logic
        OT_COND_OR,         // ||
        OT_COND_AND,        // &&
        // bit
        OT_BIT_OR,          // |
        OT_BIT_XOR,         // ^
        OT_BIT_AND,         // &
        // relational
        OT_EQ,              // ==
        OT_NE,              // !=

        OT_LT,              // <
        OT_GT,              // >
        OT_LE,              // <=
        OT_GE,              // >=
        // shift
        OT_SHL,             // <<
        OT_SHR,             // >>
        // arithmetic
        OT_ADD,             // +
        OT_SUB,             // -
        OT_MUL,             // *
        OT_DIV,             // /
        OT_MOD,             // %

        OP_NONE
    };
private:
    Expr *_left;
    Expr *_right;
    OpType _op;
    // CGClassInfo *_promotionClassInfo; // set by typeinfer
    CAVA_LOG_DECLARE();
};
```
创建节点并将左右子表达式及Op类型填入后，填充对应的位置信息，维护ASTContext(用于记录所有的AST信息)

```c++
// createBinaryOpExpr
CREATE_NODE_IMPL_ARG3(BinaryOpExpr,
                      Expr *,
                      BinaryOpExpr::OpType,
                      Expr *);

#define CREATE_NODE_IMPL_ARG3(T, T1, T2, T3)                        \
T *NodeFactory::create##T(ASTContext &astCtx, Location &location,   \
                          T1 arg1, T2 arg2, T3 arg3)                \
CREATE_NODE_IMPL_BODY(T, arg1, arg2, arg3)

#define CREATE_NODE_IMPL_BODY(T, ...)                               \
{                                                                   \
    T *val = new T(__VA_ARGS__);                                    \
    val->setLocation(location);                                     \
    astCtx.addNode<T>(val);                                         \
    astCtx.addNode<TypeNode>(val);                                  \
    astCtx.addNode<ASTNode>(val);                                   \
    val->beParent(__VA_ARGS__);                                     \
    return val;                                                     \
}
```
cava AST 设计大纲
Overall

    编译模块(Module): has a module
    编译单元(CompilationUnit): has Package Impot and ClassDecl (0 1 or more)
    类(ClassDecl): has className and ClassBody
    ClassBodyDecl: has ClassMemberDecl (0 1 or more)

    类成员(ClassMemberDecl): is a
        构造(ConstructorDecl): has className, a list of Formal and a block
        Formal: has name and TypeNode
        block: has a CompoundStmt Stmt

    字段(FieldDecl): has TypeNode and VarDecl
        VarDecl: has a valName and maybe with a Expr as initializer
        方法(MethodDecl): has methodName a list of Formal and a block
    类型(TypeNode) 语句(Stmt) 表达式(Expr)

TypeNode

    基础类型(CanonicalTypeNode): boolean, char, int, double ...
    class类型(AmbTypeNode): unresolved class type (除了基础类型，和数组类型，其余都是class类型)
    数组类型(ArrayTypeNode): has a TypeNode and dims

Stmt

    CompoundStmt: { ...; ...; } contain multi Stmts
    EmptyStmt
    ExprStmt: has a Expr
    BreakStmt
    ContinueStmt
    ReturnStmt
    LocalVarDeclStmt: has TypeNode and VarDecl
    IfStmt: has a ifExpr ifStmt and may has elseStmt
    ForStmt: a list of initStmt, stopStmt, updateStmt and bodyStmt
    DoWhileStmt
    WhileStmt
    SwitchStmt

Expr

    ArrayInitExpr: {1, 2, 3}
    ConditionalExpr: a > b ? 0 : 1
    BinaryOpExpr: && || | & ^ == >= <= > < != >> << + - * / % ...
    UnaryOpExpr: ++ -- !
    LiteralExpr: 1 1.1 'a' "abc" null ...
    NewExpr: new class
    NewArrayExpr
    FieldAccessExpr
    AssignExpr: = += -= ...
    ArrayAccessExpr
    CallExpr
    AmbExpr: a.b.c.d

AST改写插件

cava支持多种用户自定义的插件，其中重要的一类是自定义AST改写插件，由于在AST层面上，能够拿到整颗语法树的信息，可以很方便的进行一些改写语法树的操作，使得脚本语言更加灵活，可以在用户代码无感知的情况下做一些改写工作，比如可以更好的做到版本兼容问题，帮助用户完成一些代码逻辑。AST插件的执行位置在生成AST之后。以下介绍几种插件：
自动生成return语句的插件

用于检测用户在函数的函数中未实现return语句，插件自动填充return语句，该功能仅限返回值为void使用，其余类型无法确定返回值，因此加入了检测分支为实现return即报错。
默认构造函数插件

用于对为实现构造函数的类自动生成的默认构造函数

bool AddDefaultCtor::process(ASTContext &astCtx) {
    for (auto classDecl : astCtx.getClassDecls()) {  // for all class
        if (!classDecl->getCtors().empty() ||
            ASTUtil::hasNativeFunc(classDecl))    // check has ctor func
        {
            continue;
        }
        // use NodeFactory build Ctor
        auto modifier = NodeFactory::allocModifier(astCtx);
        auto name = &classDecl->getClassName();
        auto formals = astCtx.allocFormalVec();
        Location loc;
        auto type = NodeFactory::createCanonicalTypeNode(astCtx,
            loc, CanonicalTypeNode::CT_VOID);  //create return type
        auto stmtVec = astCtx.allocStmtVec();
        auto returnStmt = NodeFactory::createReturnStmt(astCtx, loc, NULL);
        stmtVec->push_back(returnStmt);
        auto body = NodeFactory::createCompoundStmt(astCtx, loc, stmtVec);
        auto ctor = NodeFactory::createConstructorDecl(astCtx,
            loc, modifier, name, formals, type, body);
        classDecl->addCtor(ctor);
    }
    return true;
}

报错信息

报错信息中定义了错误类型，报错的位置信息，以及具体的错误内容，错误信息需要分布在编译的各个阶段产生，如词法语法错误，插件报错，类型系统的错误，类型推导阶段错误，codegen报错，jit报错等。也需要思考如何才能报错精准，能够让用户清晰的知道自己的错误在哪里，cava的报错会向java靠近，目前的实现还不尽如人意，后续版本中会逐渐完善报错内容的精准度，以及覆盖所有错误分支的测试。
类型系统

类型分为基础类型，数组类型和class类型三个大类。

我们引入了类型系统来管理所有的基础类型，数组类型以及class类型，提供了注册类型，管理类型的功能。
基础类型

基础类型是cava原生的一些类型，如void，boolean，byte，int，double等，与java不同的一点是，我们引入了unsigned类型，方便与c++做交互，基础类型间允许相互之间的自动转换以及强制转换，如int类型的a，可以转成(long)a。cava通过TypePromotion定义转换规则，参考java promotion实现。
class类型

由class 定义的类型均称为cava的class类型，class类型中包含每个类型所属的module，package等信息，能够记录类型的生命周期，作用域，类型间的关系等功能。

与java一致，我们引入了package概念，每个class类型都有对应的package，用以区分不同的类。

cava是以module形式管理代码的，类型的注册和生命周期都是基于module产生的，module分为external和internal两类，external允许外部module调用本module中的类型，用于做跨模块的链接，而internal设计为不允许外部module使用，属于私有module。
数组类型

数组类型由数组的维数和其基类型（class类型或基础类型）共同组成，cava定义数组类型，数组可以显示的调用length:

template<typename T>
class CavaArrayType
{
public:
    int64_t length;
    T *getData() { return _data; }
    void setData(T *data) { _data = data; }
private:
    T *_data;
}

可以看出，不同维数的数组是不一样的类型，因此，当生成n维数组的时候，我们会递归的生成n-1维到1维数组类型。
类型推导 & 检测

类型推导和检测是在codegen前做的一步重要工作，由于cava是一门强类型语言。在生成IR前，cava会遍历AST确定所有变量表达式的类型。因此，在所有的表达式中所包含的参数类型都有严格的要求，比如boolean类型不能做加减等运算，int + long 返回的类型经过向上转型原则为long等。

因此，cava会遍历整颗语法树中的所有变量常量等做类型的推导检测，以保证符合语法。
IR & Codegen

在经历完以上步骤后的语法树，我们正式用到了llvm，接下来我们将使用llvm生成语法树对应的LLVM IR(LLVM 自带的中间码)。

llvm IR 从Module -> Function -> Basic Block -> Instruction，分为不同的层次，囊括了一门语言基本结构。llvm Module是llvm的基本编译单元。

image
cava生成IR的步骤：

    生成Module

llvm Module构造，传入llvm::Context，llvm Context初始构造可以为空

llvm::Module(moduleName, llvmContext); // string name, llvm::Context *context

    遍历Module中的所有的类（Module -> cava Class）
    生成类中所有的构造及方法，构造函数是特殊的方法（cava Class -> cava Ctor, Function), cava Ctor 是特殊的Function

llvm Function构造，需要在对应的llvm Module中插入，传入function Name以及llvm::FunctionType

llvm::FunctionType 构造需要传入返回值类型和参数列表和是否变参

llvm::FunctionType::get(retLLVMType, params, false); // Type *Result, ArrayRef<Type *> Params, bool isVarArg

llvm::cast<llvm::Function>(_module->getOrInsertFunction(funcName, funcType)); // string name, llvm::FunctionType *funcType

    生成方法对应的代码块(Function -> Basic Block)

llvm BasicBlock 构造需要llvm Context，BasicBlock name，所属function等信息，代码块相当于{}

llvm::BasicBlock *createBasicBlock(const llvm::Twine &name = "",
    llvm::Function *parent = nullptr,
    llvm::BasicBlock *before = nullptr)
{
    return llvm::BasicBlock::Create(_context, name, parent, before);
}

    生成代码块中的语句(Basic Block -> cava Stmt)

Stmt和Expr 对应到llvm中均为llvm::Instructions

引入llvm::IRBuilder 用于辅助生成llvm Instructions，插入到对应的 Basic Block 中。

irBuilder(context); // llvm::Context *context
irBuilder.SetInsertPoint(entryBB); // llvm::BasicBlock *entryBB

分支语句的生成，以if语句为例：

bool CodeGenFunction::handleIfStmt(IfStmt *ifStmt) {
    llvm::BasicBlock *thenBlock = createBasicBlock("if.then");
    llvm::BasicBlock *contBlock = createBasicBlock("if.end");
    llvm::BasicBlock *elseBlock = contBlock;
    if (ifStmt->getElse()) {
        elseBlock = createBasicBlock("if.else");
    }
    emitBranchOnBoolExpr(ifStmt->getCond(), thenBlock, elseBlock);
    if (_error) {
        emitBlock(thenBlock, true);
        emitBlock(contBlock, true);
        if (ifStmt->getElse()) {
            emitBlock(elseBlock, true);
        }
        return false;
    }
    // if.then
    emitBlock(thenBlock);
    handleStmt(ifStmt->getThen());
    emitBranch(contBlock);
    // else
    if (ifStmt->getElse()) {
        emitBlock(elseBlock);
        handleStmt(ifStmt->getElse());
        emitBranch(contBlock);
    }
    // Handle the continuation block for code after the if.
    emitBlock(contBlock, true);
    return true;
}

    生成表达式的IR(cava Stmt -> cava Expr)

同理，使用 llvm::IRBuilder 工具生成Expr对应的指令集。
异常检测

目前cava的异常检测还比较弱小，不支持用户try，catch逻辑

现有的异常检测实现方法是在所有的数组下标调用前，除法前以及对象下标访问前，进行判定是否合法，将if语句IR植入到代码中，使用if语句判断实现，遇到异常进行标记，并逐层返回。目前支持的异常检测包括：

    数组边界检测
    除0检测
    null对象下标访问检测

内存管理

cava不提供类似JVM的GC机制，作为一门脚步语言，采用允许用户自定义的内存分配方式。目前默认的简单内存实现是使用mem pool，作为脚步语言内存的持有一直到cava生命周期结束。

void *_cava_alloc_(CavaCtx *ctx, size_t size, int flag) {
    if (size == 0) {
        ++size;
    }
    CavaAlloc *cavaAlloc = (CavaAlloc *)ctx->userCtx;
    void *ret = cavaAlloc->alloc(size);
    if (flag && ret) {
        memset(ret, 0, size);
    }
    return ret;
}
void *alloc(size_t size) {
    return _pool.allocate(size);
}
autil::mem_pool::Pool _pool;

在CavaCtx 类中包含了可自定义的内存管理工具userCtx，所有的cava函数的第一项非this指针参数，均为 *CavaCtx，用于在每个方法中管理内存和异常信息。

以ha3调用cava举例，ha3使用mem pool自定义了Ha3CavaAllocator用于cava内存管理，在每个线程开始时创建cavaCtx的Ha3CavaAllocator，在调用插件的接口处传入cavaCtx，用于执行cava脚本
score = _scorerModuleInfo->scoreFunc(_scorerObj, _cavaCtx, doc);在线程结束前析构Ha3CavaAllocator，释放资源。
Pass

截止到目前，已经生成了未经过Pass优化前的llvm IR代码，通过llvm::errs() << module; 打印出llvm Module 对应的IR代码：

cava代码

class Example {
    static int add(int a, int b) {
        return a + b;
    }
    static int main() {
        int a = 3;
        int b = 4;
        if (a == 0)
            return 0;
        return add(a, b);
    }
}

对应的未经过pass优化的IR，由于cava有一些内置的异常检测，以及未经过任何pass优化，所以会显得复杂点，后续会将异常检测重新设计，不再程序中内置检测，能够减少指令数，

define i32 @_ZN7Example3addEP7CavaCtxii(%class.CavaCtx* %"@cavaCtx@", i32 %a, i32 %b) {
    entry:
        %"@cavaCtx@1" = alloca %class.CavaCtx*
        store %class.CavaCtx* %"@cavaCtx@", %class.CavaCtx** %"@cavaCtx@1"
        %a2 = alloca i32
        store i32 %a, i32* %a2
        %b3 = alloca i32
        store i32 %b, i32* %b3
        %0 = load i32, i32* %a2
        %1 = load i32, i32* %b3
        %add = add i32 %0, %1
        ret i32 %add
}

define i32 @_ZN7Example4mainEP7CavaCtx(%class.CavaCtx* %"@cavaCtx@") {
    entry:
        %"@cavaCtx@1" = alloca %class.CavaCtx*
        store %class.CavaCtx* %"@cavaCtx@", %class.CavaCtx** %"@cavaCtx@1"
        %a = alloca i32
        store i32 3, i32* %a
        %b = alloca i32
        store i32 4, i32* %b
        %0 = load i32, i32* %a
        %eq = icmp eq i32 %0, 0
        %1 = zext i1 %eq to i8
        %tobool = icmp ne i8 %1, 0
        br i1 %tobool, label %if.then, label %if.end

    if.then:                                          ; preds = %entry
        ret i32 0

    if.end:                                           ; preds = %entry
        %2 = load %class.CavaCtx*, %class.CavaCtx** %"@cavaCtx@1"
        %3 = load i32, i32* %a
        %4 = load i32, i32* %b
        %5 = call i32 @_ZN7Example3addEP7CavaCtxii(%class.CavaCtx* %2, i32 %3, i32 %4)
        %6 = load %class.CavaCtx*, %class.CavaCtx** %"@cavaCtx@1"
        %exception = getelementptr inbounds %class.CavaCtx, %class.CavaCtx* %6, i32 0, i32 1
        %7 = load i32, i32* %exception
        %ne = icmp ne i32 %7, 0
        br i1 %ne, label %if.then2, label %if.end4

    if.then2:                                         ; preds = %if.end
        %8 = load %class.CavaCtx*, %class.CavaCtx** %"@cavaCtx@1"
        %exception3 = getelementptr inbounds %class.CavaCtx, %class.CavaCtx* %8, i32 0, i32 1
        store i32 1, i32* %exception3
        ret i32 0

    if.end4:                                          ; preds = %if.end
        ret i32 %5
}

Pass 优化及编写，这也是编译语言的精髓之处，不幸的是，笔者还未深入这一领域，cava参考了clang -O2 的优化pass，执行了FunctionPasses， ModulePasses， CodeGenPasses等优化，使得性能接近c++，不过c++ 的pass有些过于复杂，不适合JIT阶段使用，以及JIT独有的PGO，根据线上真实场景做codegen等优化尚未实现，这里面的性能提升空间还是很有潜力的，希望与大家一同探究。（题外话，随着对pass的了解，可以说未涉及pass的编译器还只是初级阶段。）

下文中会提到，处于性能考虑，我们也仿照llvm 的Clone Module，类似的实现了一个可以跨Module 的clone function Pass，用于将加载的bc module inline 到其他module中，减少函数调用。

bool CavaModule::cloneGlobals() {
    auto module = _bitCodeManager.getModule(); // 取出bc 中的moduke
    if (!module) {
        return true;
    }
    if (!createDsoHandle(module)) { // clone __dso_handle
        return false;
    }
    if (!createCxaAtExit(module)) { // clone __cxa_atexit
        return false;
    }
    if (!createGlobalVariables(module)) { // clone GV, 全局变量
        return false;
    }
    if (!createCxaGlobalCtors(module)) { // clone cxaGlobalCtor
        return false;
    }
    return true;
}

__dso_handle，__cxa_atexit，用于c++链接
JIT & 执行
JIT

llvm 同时支持 AOT编译和JIT编译，JIT编译依赖于llvm TargetMachine，targetMachine 作为llvm 针对不同机器指令集的后端接口，可以根据不同的指令集产出不同的机器码，同时，也可以根据不同指令集进行pass优化。targetMachine详细的针对不同指令集的配置信息可以参考clang，cava只支持了x86-64机型。

cava JIT通过llvm ORC来生成jit编译, ORC编译需要定义一个llvm::orc::IRCompileLayer。

// 需要定义一个Compiler类，用于执行各类pass优化
_compileLayer.reset(new CompileLayerT(_objectLayer,
    CavaCompiler(_targetMachine.get(), _config.debugIR)));
auto resolver = llvm::orc::createLambdaResolver(
    [cavaModule, this](const std::string &name) {
        if (auto sym = findMangledSymbol(name, cavaModule))
            return sym;
        return llvm::JITSymbol(nullptr);
    },
    [](const std::string &S) { return nullptr; });
auto handle = _compileLayer->addModuleSet(
    singletonSet(cavaModule->getLLVMModule()),
    llvm::make_unique<llvm::SectionMemoryManager>(),
    std::move(resolver));

执行代码

执行代码通过找到函数符号对应的地址，直接调用function即可

typedef int (*MainProtoType)(CavaCtx *);
llvm::JITSymbol jitSymbol = cavaJit->findSymbol(cavaModule->getMangleMainName());    // mangle后的name，下一章会详细介绍
MainProtoType mainFunc = (MainProtoType) jitSymbol.getAddress();
if (!mainFunc) {
    cout << "no main found" << endl;
    return 0;
}
int ret = mainFunc(&cavaCtx);

与c/c++的交互

cava 的设计之初就是追求高性能，尤其是与c++的交互
mangle

cava通过生成与clang/gcc/intel编译c++标准一致的函数符号，来直接调用c++的函数。具体实现参考clang 的mangle逻辑，详情可以查看 “llvm-src/lib/AST/ItaniumMangle.cpp”，将cava的函数名生成与c++ mangle规则一致的函数名，如

static int add(int a, int b) 转换成 define i32 @_ZN7Example3addEP7CavaCtxii(%class.CavaCtx* %"@cavaCtx@", i32 %a, i32 %b)，CavaCtx是上文提到的cava自带的参数
bc加载

cava 与c++的高性能交互，来源于两者均基于llvm实现编译器，拥有一致的中间代码，既可以采用mangle后调用符号名一致的函数。也可以有更高性能的交互，那就是把c++代码或者cava代码提前编译成bc文件，再通过llvm IRReader 加载整个module，实现进一步的联合编译，pass优化。c++如何生成bc参考下文的常用命令。

image
跨模块inline编译

有了加载bc后，可以将cava原生代码和c++代码联合在一起编译，但是仍未解决cava调用c++函数这一层函数调用的开销，于是就有了跨模块inline的pass设计。我们利用IR定制了一个跨模块clone function的Pass，将不同module的函数及全局变量等通过递归的形式clone到本module中，再进行inline 优化，从而减少了函数调用。
参考 & 工具

    Kaleidoscope tutorial
    llvm tools
