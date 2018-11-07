#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
/*
 * note Integer overflow & time limited
 * 
 */
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (nums.empty() ){
	return false;
    }
    set<long> ss;
    for (int i = 0; i < nums.size(); ++i){
	if (i > k) {
	    ss.erase(nums[i-k-1]);
	}
	auto it = ss.lower_bound((long)nums[i]-t);
	if (it != ss.end() && (*it)-nums[i] <= t) return true;
	ss.insert(nums[i]);
    }
    return false;

}

int main( int argc, char *argv[] ) {
    vector<int> nums = {1, 2, 3, 1 } ;
    int k  = 3;
    int t  = 0;
    cout << containsNearbyAlmostDuplicate(nums, k, t) << endl;

    return 0;
}
