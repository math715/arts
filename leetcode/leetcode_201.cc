#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int rangeBitwiseAnd(int m, int n) {

    int k = 0;
    while (m != n ){
	m >>= 1;
	n >>= 1;
	k++;
    }
    return m << k;

            
}

int main( int argc, char *argv[] ) {
    cout << rangeBitwiseAnd(25, 30) << endl;;

   return 0;
}
