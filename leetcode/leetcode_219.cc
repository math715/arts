#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if (nums.empty() ){
	return false;
    }
    set<int> s;
    for (int j = 0; j < k && j < nums.size(); ++j){
	if (s.find(nums[j]) != s.end()){
	    return true;
	} else {
	    s.insert(nums[j]);
	}
    }
    for (int i = k; i < nums.size(); ++i){
	if (s.find(nums[i]) != s.end()){
	    return true;
	} else {
	    s.insert(nums[i]);
	}
	s.erase(nums[i-k]);
    }
    return false;

}

int main( int argc, char *argv[] ) {
    vector<int> nums = {13, 23, 1, 2, 3};
    int k = 5;
    cout << containsNearbyDuplicate(nums, k) << endl;

    return 0;
}
