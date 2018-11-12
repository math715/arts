#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
int missingNumber(vector<int>& nums) {
    long n = nums.size();
    long result = (n * ( n + 1) ) >> 1;
    for (auto num : nums){
	result -= num;
    }
    return result;
}

int main( int argc, char *argv[] ) {
    vector<int> nums = {0, 1, 3};
    cout << missingNumber(nums) << endl;

    return 0;
}
