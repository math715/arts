
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> results;
    vector<int> temp; 
    results.push_back(temp);
    int last_idx = 0;
    for (int i = 0; i < nums.size(); ++i){
	int start_idx = 0;
	if (i > 0 && nums[i] == nums[i-1]){
	    start_idx = last_idx;
	}
	int cur_size = results.size();
	last_idx = cur_size;
	for (int j  = start_idx ; j < last_idx; ++j) {
	    vector<int> t = results[j];
	    t.push_back(nums[i]);
	    results.push_back(t);
	}
    }
    return results;
}



int main() {
    vector<int> nums = {1, 2, 2};
    auto ress = subsetsWithDup(nums);
    for (auto res : ress) {
	for (auto r : res) {
	cout << r << " ";
	}
	cout << endl;
    }

    return 0;
}
