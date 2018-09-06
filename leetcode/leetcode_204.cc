#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int countPrimes(int n) {
    vector<bool> pt;
    pt.resize(n + 1, false);
    int result = 0;
    for (int i = 2; i < n; ++i ){
	if (pt[i] == false) {
	    pt[i] = true;
	    result ++;
	    for (int j = i + i; j < n; j += i ){
		pt[j] = true;
	    }
	}
    }
    return result;
    

}

int main( int argc, char *argv[] ) {
    cout << countPrimes(10) << endl;
    cout << countPrimes(23) << endl;

   return 0;
}
