#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numDecodings(string s) {
    int result = 0;
    vector<int> A;
    A.resize(s.size() + 1, 0);
    A[0] = 1;
    int n = s.size();
    if (s[0] != '0'){
	A[1] = 1;
    } else {
	return 0;
    }
    for (int i = 2; i <= n; ++i){
	if (s[i-1] != '0'){
	    if (s[i-2] == '0' || s[i-2] > '2' || s[i-2] == '2' && s[i-1] > '6'){
		A[i] = A[i-1];
	    } else {
		A[i] = A[i-1] + A[i-2];
	    }
	} else {
	    if (s[i-2] == '0' || s[i-2] >= '3'){
		return 0;
	    }
	    A[i] = A[i-2];
	}
    }
    return A[n];
}
int main( int argc, char *argv[] ) {
    // cout << numDecodings("0") << endl;;
    // cout << numDecodings("111206") << endl;
    // cout << numDecodings("111706") << endl;
    // cout << numDecodings("112736") << endl;
    cout << numDecodings("312736") << endl;
    return 0;
}
