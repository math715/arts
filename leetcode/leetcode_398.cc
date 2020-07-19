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
class Solution{
public:
    Solution(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i) {
			table[nums[i]].push_back(i);
		}
    }
    int pick(int target) {
		auto nums = table[target];
		int idx = rand() % nums.size();
		return nums[idx];
    }
	unordered_map<int, vector<int>> table;
};
void test() {
	vector<int> nums = {1,2,3,3,3};
	Solution* obj = new Solution(nums);
	int target = 3;
	int param_1 = obj->pick(target);
	cout << param_1 << endl;
	param_1 = obj->pick(target);
	cout << param_1 << endl;
	param_1 = obj->pick(target);
	cout << param_1 << endl;
}

int main (int argc, char **argv) {
	test();
	return 0;
}
