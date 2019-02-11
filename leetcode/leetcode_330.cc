#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int minPatches(vector<int>& nums, int n) {
    int patch = 0;
    int idx = 0;
    int miss = 1;
    while(miss <= n) { 
	if (idx < nums.size() && miss >= nums[idx]) {
	    miss += nums[idx++];
	} else {
	    miss += miss;
	    patch++;
	}
    }
    return patch;
}


int main( int argc, char *argv[] ) {
    vector<int> nums = {1,3};
    int n = 6;
    cout << minPatches(nums, n) << endl;;

    return 0;
}
