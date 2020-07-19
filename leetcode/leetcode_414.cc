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
int thirdMax(vector<int>& nums) {
	vector<int> vs;
	int mn = nums[0];
	int mx = nums[0];
	vs.push_back(nums[0]);
	for (int i = 1; i < nums.size(); ++i) {
		bool find = false;
		for (int j = 0; j < vs.size(); ++j) {
			if (vs[j] == nums[i]) {
				find = true;
				break;
			}

		}
		if (find) {
			continue;
		}
		if (vs.size() < 3) {
			vs.push_back(nums[i]);
			mn = min(mn, nums[i]);
			mx = max(mx, nums[i]);
		} else {
			if (nums[i] > mn) {
				for (int j = 0; j < 3; ++j) {
					if (vs[j] == mn) {
						vs[j] = nums[i];
					}
				}
				mn = vs[0];
				for (int j = 1; j < 3; ++j) {
					mn = min(mn, vs[j]);
				}
			}
		}
	}
	if (vs.size() < 3 ) {
		return mx;
	}
	return mn;
}

void test() {
	vector<int> nums = {3, 2, 1};
	cout << thirdMax(nums) << endl;
	nums = {1, 2};
	cout << thirdMax(nums) << endl;
	nums = {2, 2, 3, 1};
	cout << thirdMax(nums) << endl;
	nums = {2, 2, 2, 2};
	cout << thirdMax(nums) << endl;
	nums = {1,2,2,5,3,5};
	cout << thirdMax(nums) << endl;
}

int main (int argc, char **argv) {
	test();
	return 0;
}
