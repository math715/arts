#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result;
    int n = nums.size();
    result.resize(n, 0);
    result[n - 1] = nums[n-1];
    for (int i = n-2; i >= 0; --i) {
	result[i] = result[i+1] * nums[i];
    }
    int pre = 1;
    for (int i = 0; i < n; ++i) {
	if (i < n - 1) {
	    result[i] = result[i+1] * pre;
	} else {
	    result[i] = pre;
	}
	pre = i == 0? nums[i]: pre * nums[i];
    }
    return result;
}
int main( int argc, char *argv[] ) {
    // vector<int> nums = {1, 2, 3, 4};
    vector<int> nums = {0, 1, 2};
    auto vs = productExceptSelf(nums);
    for (auto v : vs) {
	cout << v << " ";
    }
    cout << endl;

    return 0;
}
