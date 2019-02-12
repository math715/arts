#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int integerBreak(int n) {
    vector<long> dp;
    dp.resize(n + 1, 0);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
	dp[i] = 1 * (i - 1);
	for (int j = 2; j <= i / 2; ++j) {
	    long w = j * (i - j);
	    dp[i] = max(w, dp[i]);
	    dp[i] = max(j * dp[i-j], dp[i]);
	    dp[i] = max(dp[j] * dp[i-j], dp[i]);
	}
    }
    for (int i = 0; i <= n; ++i ) {
	cout << i << " " << dp[i] << endl;
    }
    return dp[n];

}

int main( int argc, char *argv[] ) {
    cout << integerBreak(2) << endl;
    cout << integerBreak(10) << endl;
    cout << integerBreak(14) << endl;
    cout << integerBreak(58) << endl;

    return 0;
}
