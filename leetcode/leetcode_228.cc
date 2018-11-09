#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    if (nums.empty()){
	return result;
    }
    if (nums.size() == 1) {
	result.push_back(std::to_string(nums[0]));
	return result;
    }
    int pre = 0;
    for (int i = 1; i < nums.size(); ++i) {
	if (nums[i] != nums[i-1] + 1) {
	    if (i-1 == pre) {
		result.push_back(to_string(nums[pre]));
	    } else {
		string t = to_string(nums[pre]) + "->" + to_string(nums[i-1]);
		result.push_back(t);
	    }
	    pre = i;
	}
    }
    if (nums[nums.size() -1] == nums[nums.size() - 2] + 1) {
	string t = to_string(nums[pre]) + "->" + to_string(nums[nums.size()-1]);
	result.push_back(t);
    } else {
	result.push_back(to_string(nums[nums.size() - 1]));
    }
    return result;

}

int main( int argc, char *argv[] ) {
    vector<int> nums = {0, 2, 3, 4, 6, 8, 9 };
    auto vs = summaryRanges(nums) ;
    for (auto v : vs ){
	cout << v << endl;
    }

    return 0;
}
