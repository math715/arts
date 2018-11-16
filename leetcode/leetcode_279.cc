#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


int numSquares(int n) {
    vector<int> dp;
    dp.resize(n+1, INT32_MAX);
    for (int i = 1; i * i <= n; ++i){
	dp[i*i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
	for (int j = 1; i + j * j <= n; ++j) {
	    dp[i+j*j] = min(dp[i] + 1, dp[i+j*j]);
	}
    }
    return dp[n];
}


int main( int argc, char *argv[] ) {
    cout << numSquares(1) << endl;
    cout << numSquares(12) << endl;
    cout << numSquares(15) << endl;

    return 0;
}
