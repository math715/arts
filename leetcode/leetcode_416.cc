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

bool canPartition(vector<int>& nums) {
	int sum = 0;
	for (auto num : nums) {
		sum += num;
	}
	if (sum & 1) {
		return false;
	}
	sum = sum / 2;
	int n = nums.size();
	vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
	for (int i = 0; i <= n; ++i ) {
		dp[i][0] = true;
	}
	for (int i = 1; i <= n; ++i ) {
		for (int j = 0; j <=sum; ++j) {
			dp[i][j] = dp[i-1][j]; 
			if ( j >= nums[i-1]) {
				dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
			}
		}
	}
	return dp[n][sum];

}

void test() {
	vector<int> nums = {1, 5, 11, 5};
	std::cout << canPartition(nums) << std::endl;


}

int main (int argc, char **argv) {
	test();
	return 0;
}
