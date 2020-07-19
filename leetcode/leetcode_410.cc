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

int check(vector<int> &nums, int m, int k) {
	int sum = 0; 
	int count = 1;
	for (int i = 0; i <  nums.size(); ++i) {
		if (nums[i] > k) {
			return 0;
		}
		if (sum + nums[i] > k) {
			count++;
			sum = nums[i];
		} else {
			sum += nums[i];
		}
	}
	return count <= m ? 1 : 0;
}

int splitArray(vector<int>& nums, int m) {
	int left = 0, right = INT32_MAX;
	while(left <= right){
		int mid = left + (right - left) /2;	
		if (check(nums, m, mid)) {
			right = mid - 1;
		} else {
			left  = mid + 1;
		}
	}
	return left;
}


void test() {
	vector<int> v{7,2, 5, 10, 8};
	cout << splitArray(v, 2) << endl;
}

int main (int argc, char **argv) {
	test();
	return 0;
}
