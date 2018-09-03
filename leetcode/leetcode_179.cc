#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string largestNumber(vector<int>& nums) {
    vector<string> strs;
    for ( auto num : nums){
	strs.push_back(to_string(num));
    }
    sort(strs.begin(), strs.end(), [](const string &s, const string &t) {
	    auto s1 = s + t;
	    auto s2 = t + s;
	    return s1 > s2;
	    });
    string result;
    for (auto str : strs){
	result += str;
    }
    bool flag = true;;
    for (int i = 0; i < result.size(); ++i){
	if (result[i] != '0'){
	    flag = false;
	    break;
	}
    }
    return flag ? "0" : result;
}

int main () {
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums) << endl;
    return 0;
}
