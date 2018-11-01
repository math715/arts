#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;


int sub_rob(vector<int>&nums, int s, int e) {
    int n = e - s + 1;
    vector<int> d;
    d.resize(nums.size(),0);
    d[0] = nums[s];
    d[1] = max(nums[s], nums[s+1]);
    for (int i = 2; i < n; ++i ){
	d[i] = max(d[i-2] + nums[s+i], d[i-1]);
    }
    return d[n-1];
}

int rob(vector<int>& nums) {
    int result = 0;
    int n = nums.size();
    if (n <=0){
	return result;
    } else if (n == 1){
	return nums[0];
    } else if (n == 2 ) {
	return max(nums[0], nums[1]);
    } else {
	return max(sub_rob(nums, 0, n - 2), sub_rob(nums, 1, n-1));
    }

}

int main( int argc, char *argv[] ) {
    vector<int> nums= {1, 2, 3, 1};
    cout << rob(nums) << endl;

    return 0;
}
