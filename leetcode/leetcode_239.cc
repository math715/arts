#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    multiset<int, greater<int>> ms;
    for (int i = 0; i < k - 1; ++i){
	ms.insert(nums[i]);
    }
    
    for (int i = k-1; i < nums.size() ; ++i ) {
	ms.insert(nums[i]);
	result.push_back(*ms.begin());
	auto it = ms.find(nums[i-k+1]);
	ms.erase(it);
    }
    return result;


}

int main( int argc, char *argv[] ) {
    // vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    int k = 4;
    auto vs = maxSlidingWindow(nums, k);
    for (auto v : vs ) {
	cout << v << " ";
    }
    cout  << endl;

    return 0;
}
