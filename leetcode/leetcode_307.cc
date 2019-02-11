#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
class NumArray {
    public:
	int size_;
	int L;
	vector<int> nums_;
	vector<int> bits_;
	NumArray(vector<int> nums) {
	    nums_ = nums;
	    bits_.resize(nums_.size() +1, 0);
	    for (int i = 0; i < nums.size(); ++i) {
		adjust(i, nums[i]);
	    }
	}
	void adjust(int i, int val) {
	    i++;
	    while (i <= nums_.size()) {
		bits_[i] += val;
		i += i & -i;
	    }
	}

	void update(int i, int val) {
	    int delta = val - nums_[i];
	    nums_[i] = val;
	    adjust(i, delta);
	}

	int sumRange(int i, int j) {
	    return getSum(j) - getSum(i-1);
	}
	int getSum(int i) {
	    i++;
	    int sum = 0;
	    while (i > 0 ) {
		sum += bits_[i];
		i -= (i&-i);
	    }
	    return sum;
	}
};

int main( int argc, char *argv[] ) {
    vector<int> nums = {1, 3, 5};
    NumArray num_array(nums);
     std::cout << num_array.sumRange(0, 2) << endl;

    return 0;
}
