#include <iostream>
#include <vector>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
	vector<int> dp;
	dp.resize(amount +1, INT32_MAX);
	dp[0];
	for (auto c: coins) {
		if (c <= amount) {
			dp[c] = 1;
		}
	}
	for (int i = 1; i <= amount; i++) {
		for (auto c : coins) {
			if (i - c > 0 && dp[i-c] != INT32_MAX) {
				dp[i] = min(dp[i], dp[i-c]+1);
			}
		}
		cout << i << "\t"<< dp[i] << endl;
	}
	return dp[amount] == INT32_MAX? -1 : dp[amount];

}

int main() {
	vector<int> coins = {2};
	int amount = 3;
	cout << coinChange(coins, amount) << endl;;
	return 0;
}
