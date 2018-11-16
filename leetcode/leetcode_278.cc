#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
bool isBadVersion(int n) {
    cout << n << endl;
    return n >= 1702766719;
}
int firstBadVersion(int n) {
    long l = 0; 
    long r = n;
    while (l <= r) {
	long mid = (l + r) >> 1;
	if (isBadVersion(mid)){
	    r = mid - 1;
	} else {
	    l = mid + 1;
	}
    }
    return l;

}

int main( int argc, char *argv[] ) {
    cout << firstBadVersion(2126753390) << endl;

    return 0;
}
