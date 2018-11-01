#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 */

int minSubArrayLen(int s, vector<int>& nums) {
    int l = 0;
    int r = -1;
    int result = 0;
    int m = nums.size() + 1;
    int len = nums.size() ; 
    while (r<len) {
	while (result<s && r < len ){
	    result += nums[++r];
	}
	if (result >= s) {
	    m = m < r - l + 1? m : r - l + 1;
	    result -= nums[l++];
	}
    }
    return m == nums.size() + 1? 0 : m;

}


int main( int argc, char *argv[] ) {
    int s = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(s, nums) << endl;

   return 0;
}
