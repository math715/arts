#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
    map<int, int> mp;
    vector<int> result;
    int m = 1;
    for (auto num : nums){
	if (mp.find(num) == mp.end()) {
	    mp[num] = 1;
	} else {
	    mp[num]++;
	    m = mp[num] > m ? mp[num] : m;
	}
    }
    for (auto p : mp) {
	if (p.second * 3 > nums.size()){
	    result.push_back(p.first);
	}
    }
    return result;
}

int main( int argc, char *argv[] ) {
    vector<int > nums= {6, 6, 6, 7, 7};
    
    auto vs = majorityElement(nums);
    for (auto v : vs ) {
	cout << v << " ";
    }
    cout << endl;

    return 0;
}
