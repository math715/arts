#include <string>
#include <iostream>

using namespace std;
int titleToNumber(string s) {
    int result = 0;
    int t = 1;
    for (int n = s.size() - 1; n >= 0; --n){
	result = (s[n] - 'A' + 1) * t + result;
	t *= 26;
    }
    return result ;
}


int main() {
    cout << titleToNumber("AA") << endl;
    cout << titleToNumber("AAA") << endl;
    cout << titleToNumber("ZY") << endl;
}

