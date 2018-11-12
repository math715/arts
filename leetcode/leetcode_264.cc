#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
int nthUglyNumber(int n) {
    vector<int> vs;
    int i2 = 0, i3 = 0, i5 = 0;
    vs.push_back(1);
    for (int i = 1; i < 1690; ++i) {
	int a2 = vs[i2] * 2;
	int a3 = vs[i3] * 3;
	int a5 = vs[i5] * 5;
	if (a2 < a3 && a2 < a5) {
	    vs.push_back(a2);
	    i2++;
	} else if ( a2 == a3 && a3 < a5) {
	    vs.push_back(a3);
	    i2++;
	    i3++;
	} else if (a3 < a2 && a3 < a5 ) {
	    vs.push_back(a3);
	    i3++;
	} else if ( a3 < a2 && a3 == a5) {
	    vs.push_back(a3);
	    i3++;
	    i5++;
	} else if ( a5 < a2 && a5 < a3) {
	    vs.push_back(a5);
	    i5++;
	} else if (a2 == a5 && a5 < a3) {
	    vs.push_back(a5);
	    i2++;
	    i5++;
	} else if(a2 == a3 && a2 == a5) {
	    vs.push_back(a2);
	    i2++;i3++;i5++;
	}
    }
    return vs[n-1];
}
    

int main( int argc, char *argv[] ) {
    cout << nthUglyNumber(10) << endl;

    return 0;
}
