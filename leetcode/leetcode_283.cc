#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    if (nums.size() <= 1) {
	return ;
    }
    int idx  = 1;
    for (int i = 0 ; i < nums.size() ; ++i) {
	idx = idx > i ? idx : i + 1;
	while (idx < nums.size() && nums[idx] == 0){
	    idx++;
	}
	if (nums[i] == 0 && idx < nums.size())
	    swap(nums[i], nums[idx]);
    }

}

int main( int argc, char *argv[] ) {
    // vector<int> nums = {0, 1, 0, 3, 12};
    // vector<int> nums = {0, 1, 4, 3, 0};
    vector<int> nums = {4,2,4,0,0,3,0,5,1,0};
    moveZeroes(nums);
    for (auto n : nums) {
	cout << n << " ";
    }
    cout << endl;

    return 0;
}
