#include <vector>

#include <iostream>
#include <algorithm>

using namespace std;

void wiggleSort(vector<int>& nums) {
	if (nums.size() <= 1) {
		return ;
	}
	int n= nums.size();
	auto mid_ptr = nums.begin() + (n/ 2);
	nth_element(nums.begin(), mid_ptr, nums.end());
	int mid = *mid_ptr;
	cout << "mid " << mid << endl;
#define A(i) nums[(1+2*(i)) % (n|1)]
	int i = 0, j = 0, k = n - 1;
	while (j <= k) {
		if (A(j) > mid) {
			swap(A(i++), A(j++));
		} else if (A(j) < mid) {
			swap(A(j), A(k--));
		} else {
			j++;
		}
	}
	/*
	 int numSize = nums.size();
        if (numSize < 2) {
            return ;
        }
        #define A(i) nums[(2*i+1)%(numSize|1)]     //
        int midPos = 0;
        nth_element(nums.begin(), nums.begin()+numSize/2, nums.end());
        int mid = nums[numSize/2];
	cout << "mid " << mid << endl;

        int i=0, j=0, k=numSize-1;

        while (j <= k) {
            if (A(j) > mid) {
                swap (A(i++), A(j++));
            } else if (A(j) < mid) {
                swap (A(j), A(k--));
            } else {
                ++j;
            }
        }
	*/
}



int main() {
	vector<int> nums = {1,3,2,2,3,1};
	wiggleSort(nums);
	for (auto n : nums) {
		cout << n << " " ;
	}
	cout << endl;
	return 0;
}
