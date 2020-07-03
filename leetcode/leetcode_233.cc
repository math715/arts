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

int TcountDigitOne(int n)
{
    int countr = 0;
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
    }
    return countr;
}
void Test(int value) {
    cout << value << " " << countDigitOne(value) << " " << TcountDigitOne(value) << endl;
}
int main( int argc, char *argv[] ) {
    Test(13) ;
    Test(10) ;
    Test(100) ;
    Test(1000) ;

    return 0;
}
