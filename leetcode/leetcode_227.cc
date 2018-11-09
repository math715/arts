#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
using namespace std;
int calculate(string s) {
    long r = 0, pre;
    char op = '+';
    stack<long> st;
    long num = 0;
    for (int i = 0; i < s.size(); ++i) {
	if (isdigit(s[i])) {
		num = num * 10 + s[i] - '0';
	} 
	if (i == s.size()-1 || s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
	    if (op == '+') {
		st.push(num);
	    } else if (op == '-') {
		st.push(-num);
	    } else if (op == '*') {
		long a = st.top() * num ;
		st.pop();
		st.push(a);
	    } else if (op == '/') {
		long a = st.top() / num ;
		st.pop();
		st.push(a);
	    }
	    op = s[i];
	    num = 0;
	}
    }
    int res = 0;
    while(!st.empty()) {
	res += st.top();
	st.pop();
    }
    return res;

}

int main( int argc, char *argv[] ) {
    cout << calculate("5/3+1")<< endl;

    return 0;
}
