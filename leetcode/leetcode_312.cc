#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int maxCoins(vector<int>& nums) {

    vector<int> vs(nums.size() + 2, 1);
    for (int i =0 ; i < nums.size(); ++i) {
	vs[i+1] = nums[i];
    }
    int n = nums.size() + 2;
    vector<vector<int>> dp(n, vector<int>(n,0));
    for (int k = 2; k < n; ++k) {
	for (int left = 0; left < n - k; ++left) {
	    int right = left + k;
	    for (int i = left + 1; i < right; ++i) {
		int c = vs[left] * vs[i] * vs[right] + dp[left][i] + dp[i][right];
		dp[left][right] = max(dp[left][right], c);
	    }
	}
    }
    return dp[0][n-1];

}
int maxCoins1(vector<int>& nums_orig) {
    vector<int> nums(nums_orig.size() + 2, 1);
    int n = 1;
    for (auto& c : nums_orig) {
	if (c > 0) {
	    nums[n++] = c;
	}
    }
    n += 1;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int k = 2; k < n; ++k) {
	for (int left = 0; left < n - k /*aka right < n */ ; ++left) {
	    int right = left + k;
	    for (int i = left + 1; i < right; ++i) {
		// cout << "Left=" << left << ", Right=" << right << ", i=" << i << "\n";
		int candidate = nums[left] * nums[i] * nums[right]
		    + dp[left][i] + dp[i][right];
		dp[left][right] = std::max(dp[left][right], candidate);
	    }
	}
    }
    return dp[0][n-1];      
}

int main( int argc, char *argv[] ) {
    vector<int> nums ={3,1,5, 8};
    cout << maxCoins1(nums) << endl;
    cout << maxCoins(nums) << endl;

    return 0;
}
