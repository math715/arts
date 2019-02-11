#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3){
	return false;
    }

    set<int, greater<int>> ss;
    ss.insert(nums[0]);
    int idx = -1;
    for (int i = 1; i < nums.size(); ++i) {
	if(nums[i] > *ss.begin()) {
	    ss.insert(nums[i]);
	    if (ss.size() == 3) {
		return true;
	    }
	} else {
	    if (ss.size() == 1) {
		ss.erase(ss.begin());
		ss.insert(nums[i]);
	    } else {
		if (idx != -1 && nums[i] > nums[idx]) {
		    ss.clear();
		    ss.insert(nums[i]);
		    ss.insert(nums[idx]);
		    idx = -1;
		} else {
		    int a = *ss.begin();
		    ss.erase(ss.begin());
		    int b = *ss.begin();
		    if (nums[i] > b) {
			ss.insert(nums[i]);
		    } else {
			ss.insert(a);
			idx = i;
		    }
		}
	    }
	}

    }
    return false;

}

int main( int argc, char *argv[] ) {
    // vector<int> nums = {5, 4, 3, 2, 1};
    // vector<int> nums = {5, 4, 1, 2, 3};
    // vector<int> nums = {2, 1, 5, 0, 3};
    // vector<int> nums = {1, 2, -10, -8, -7};
    vector<int> nums = {11, 12, 0, 1, 8};
    cout << increasingTriplet( nums ) << endl;;

    return 0;
}
