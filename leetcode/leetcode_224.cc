#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <cassert>
#include <cctype>
using namespace std;
int calculate(string s) {
    long a = 0, b = 0, r = 0;
    stack<long> st;
    long res = 0;
    int sign = 1;
    for (int i = 0; i  < s.size(); ++i) {
	if (isdigit(s[i])) {
	    long num = 0;
	    while (isdigit(s[i]) && i <s.size()) {
		num = num * 10 + (s[i]-'0');
		i++;
	    }
	    res += sign * num;
	    i--;
	} else if (s[i] == '+') {
	    sign = 1; 
	} else if (s[i] == '-') {
	    sign = -1;
	} else if (s[i] == '('){ 
	    st.push(res);
	    st.push(sign);
	    res = 0;
	    sign = 1;
	} else if (s[i] == ')') {
	    res *= st.top(); st.pop();
	    res += st.top(); st.pop();
	}

    }
    return res;

}

int main( int argc, char *argv[] ) {
    // cout << calculate("1+1") << endl;
    // cout << calculate("1+(1+2)") << endl;
    // cout << calculate("1+(1-2)") << endl;
    // cout << calculate("-3") << endl;
    // cout << calculate("1+3") << endl;
    cout << calculate("1 + 3") << endl;
    // cout << calculate("(1+(4+5+2)-3)") << endl;
    cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;

    return 0;
}
