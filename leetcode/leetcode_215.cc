#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
    // priority_queue <int,vector<int>,less<int> >q;
    priority_queue <int,vector<int>,greater<int> >q;
    for (int i = 0; i < k ; ++i) {
	q.push(nums[i]);
    }
    for (int i = k; i < nums.size(); ++i) {
	if (q.top() < nums[i]) {
	    q.pop();
	    q.push(nums[i]);
	}
    }
    return q.top();
}

int main( int argc, char *argv[] ) {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout << findKthLargest(nums, 4) << endl;

    return 0;
}
