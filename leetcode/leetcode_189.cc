#include <vector>
#include <iostream>

using namespace std;
void rotate(vector<int>& nums, int k) {
    vector<int> vs;
    int n = nums.size();
    k = k % n;
    for (int i = n - k; i < n; ++i) {
	vs.push_back(nums[i]);
    }
    for (int i = n - 1; i >= k; --i){
	nums[i] = nums[i - k];
    }
    for (int i = 0; i < k; ++i){
	nums[i] = vs[i];
    }
}


int main() {
    vector<int> nums;
    for (int i = 0; i < 7; ++i){
	nums.push_back(i+1);
    }
    rotate(nums, 8);
    for (auto num : nums ) {
	cout << num << " ";
    }
    cout << endl;
    return 0;
}
