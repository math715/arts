#include <stack>
#include <iostream>

using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
	    if (stack_.empty()) {
		    stack_.push({x, x});
	    } else {
		    int val = x > stack_.top().second ? stack_.top().second : x; 
		    stack_.push({x, val});
	    }
    }
    
    void pop() {
	    stack_.pop();
        
    }
    
    int top() {
       return stack_.top().first; 
    }
    
    int getMin() {
	 return  stack_.top().second;

    }
    stack<pair<int, int>> stack_;
};

int main() {
	MinStack minStack ; 
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl;
	return 0;
}
