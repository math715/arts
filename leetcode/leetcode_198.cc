#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int rob(vector<int>& nums) {
    vector<int> dp;
    int n = nums.size();
    dp.resize(n);
    if (n == 0 ){
	return 0;
    } else if (n == 1 ){
	return nums[0];
    } else if (n == 2) {
	return max(nums[0], nums[1]);
    }

    dp[0] = nums[0];
    dp[1] = max(nums[1], nums[0]);
    for (int i = 2; i < n; ++i) {
	dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];

}

int main( int argc, char *argv[] ) {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob ( nums ) << endl;

    return 0;
}
