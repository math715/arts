#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int maxProduct(vector<int>& nums) {
	vector<int> max_vs;
	vector<int> min_vs;
	max_vs.resize(nums.size(), 1);
	min_vs.resize(nums.size(), 1);
	max_vs[0] = min_vs[0] = nums[0];
	int result = max_vs[0];
	for (int i = 1; i < nums.size(); ++i){
		min_vs[i] = min(nums[i], min(nums[i] * min_vs[i-1], nums[i] * max_vs[i-1]));
		max_vs[i] = max(nums[i], max(nums[i] * min_vs[i-1], nums[i] * max_vs[i-1]));
		result = max(max_vs[i], result);

	}

	return result;

}

int main() {
	vector<int> nums = {2, 3, -2, -4};
	cout << maxProduct(nums) << endl;;
	return 0;
}
