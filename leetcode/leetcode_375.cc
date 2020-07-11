#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int dfs(vector<vector<int>> &dp, int l, int r) {
	if ( l >= r) {
		return 0;
	}
	int res = INT32_MAX;
	if (dp[l][r] > 0) {
		return dp[l][r];
	}
	for (int i = l; i <= r; ++i){
		int temp = i + max(dfs(dp, l, i - 1), dfs(dp, i+1, r));
		if (temp < res) {	
			res = temp;
		}
	}
	dp[l][r] = res;
	return res;
}
int getMoneyAmount(int n) {
	vector<vector<int>> dp (n + 1, vector<int>(n+1, 0));;
	return dfs(dp, 1, n);
}

void test() {
	cout << getMoneyAmount(10) << endl;;
}

int main (int argc, char **argv) {
	test();
	return 0;
}
