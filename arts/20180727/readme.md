## pattern match
X language 

X language is toy function program language
X compiler can translate x-language into cplusplus source code
### why X compiler translate x-language into cplusplus not bitcode(LLVM BC)
- 1 deep understand c++ and compiler(fornt-end)
- 2 deep understand functions porgram
- 3 use X language implement simple distribute storage system (kv-storage system ) and distribute compute system (distribute memory compute system )





##gammer
```c++
match_expr|
    | MATCH expr { }
    | MATCH expr { match_clauses }

match_clauses
    | match_clause
    | match_clauses ',' match_clause

match_clause
    | maybe_guard_expr => block_list 


maybe_guard_expr 
    | IF expr 
    | %empty
```
## usage 

pattern match 
- 1 wildcard pattern match
- 2 constant pattern match
- 3 variable pattern match
- 4 constructor pattern match
- 5 sequence pattern match
- 6 tuple pattern match
- 7 typed pattern match

## example 


###  X 
#### 1 constant pattern match

```rust
match x {
    1 => ...
    2 => ...
    _ => ...
}
```
### 2 variable pattern match
```rust 
match x {
    i@1 => 
    o@_ => 
}
```
#### 6 tuple pattern match
```rust 
    //pair
    match x {
        (x, y) => ...
    }
    //tuple 
    match x {
        (x, y, z) => ...
    }
```
#### 8 destructuring 
```rust 
//Enums
//
```

### C++
#### constant pattern match
```c++
switch (1){
    case 1:
        ...
        break;
    case 2:
        ...
        break;
    default:
        ...
}
```

### variable pattern match
```c++

```


#### variable pattern match


###  rust
constructor typed and sequence pattern match
undenfined
#### 1 constant pattern match
```rust 
match x {
    1 => ...
    2 => ...
    _ => ...
}
```
#### 2 variable pattern match
```rust
match x {
    n@1 .. 10 => 
}
```

#### 4 tuple pattern match 
```rust
//destruct tuple
match pair {
    (x, y) => 
}
//destruct enums
enum Color{Red, Bule, Green,}
match x {
    Color::Red => ...
    Color::Bule => ...
    Color::Green => ...
}
//destruct struct 
struct Foo { x: (i32, i32), y: i32}
let foo = Foo {x: (1,2), y: 3 };
let Foo {y : i, x : j} = foo;
```


#### 7 guard pattern match
```rust 
match pair {
    (x, y) if x == y => ...
    (x, y) if x != y => ...
}
#### 8 destructuring 
```rust 


```

### scala
#### 1 constant pattern match
```scala
x match {
    case 1 => ...
    case 2 => ...
    case _ => ...
}
```
#### 2 variable pattern match
```scala 
    x match {
        case i : Int => ...
        case otherValue => ...
    }
}
```
#### 3 sequence pattern match 
```scala 
    x match {
        case List(0, _, _) => ...
        case Array(1, _*) => ...
    }
```
#### 4 tuple pattern match
```scala 
    x match {
        case (a, b) => ...
        case (a, b, c) => ...
    }
```
#### 5 constructor pattern match
```scala
    x match {
        case Person(first, "") => ...
        case Dog("Husky") => ...
    }
```
#### 6 typed pattern match
```scala 
    x match{
        case s: String => ...
        case i: Int => ...
    }
```
#### 7 guard pattern match
```scala 
    x match {
        case a if a > 0 => ...
        case a if a < 0 => ...
    }
```