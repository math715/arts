#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
vector<int> countBits(int num) {
    vector<int> result;
    if (num >= 0) {
	result.push_back(0);
    }
    if (num >= 1) {
	result.push_back(1);
    }
    long idx = 1;
    for (int i = 2; i <= num; ++i) {
	if ( i == 2 * idx) {
	    idx *= 2;
	    result.push_back(1);
	} else {
	    result.push_back(result[idx] + result[i-idx]);
	}
    }
    return result;
}

void test(int n ) {
    cout << "test : " << n << endl;
    auto vs = countBits(n);
    for (auto v : vs ) {
	cout << v << " ";
    }
    cout << endl;
}
int main( int argc, char *argv[] ) {
    test(0);
    test(1);
    test(5);
    test(10);
    return 0;
}
