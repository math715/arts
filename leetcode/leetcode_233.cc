#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
int countDigitOne(int n) {
    int result = 0;
    long i;
    for ( i = 10; i <= n; i *= 10) {
	int a = n % i ;
	int b = n / i;
	int c = (n / i) % 10;
	if (c < 2) {
	    result += b;
	    if (c==1) {
		result += a + 1;
	    }
	} else {
	    result += (c+1)*(i/10);
	}
    }
    return result;
}
int main( int argc, char *argv[] ) {
    cout << countDigitOne(13) << endl;
    cout << countDigitOne(10) << endl;
    cout << countDigitOne(100) << endl;
    cout << countDigitOne(1000) << endl;

    return 0;
}
