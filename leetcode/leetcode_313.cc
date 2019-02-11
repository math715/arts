#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
int nthSuperUglyNumber(int n, vector<int>& primes) {
    int k = primes.size();
    vector<int> idx(k, 0);
    vector<int> ress;
    int cnt = 0;
    int res = 1;
    if (n == 1) {
	return 1;
    }
    ress.push_back(1);
    for (int i = 1; i < n; ++i) {
	int m = INT32_MAX;
	int m_idx;
	for (int j = 0; j < k; ++j) {
	    int t = ress[idx[j]] * primes[j];
	    if (t < m) {
		m = t;
	    }
	}
	ress.push_back(m);
	for (int j = 0; j < k; ++j) {
	    int t = ress[idx[j]] * primes[j];
	    if (t == m) {
		idx[j]++;
	    }
	}
    }
    return ress.back();


}

int main( int argc, char *argv[] ) {
    int n = 12;
    vector<int> primes = {2, 7, 13, 19};
    cout << nthSuperUglyNumber(n, primes) << endl;

    return 0;
}
