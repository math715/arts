#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
	int result = 0;
	int *count = new int[32];
	int n = nums.size();
	for (int i = 0; i < 32; ++i){
		for (int j = 0; j < n ; ++j){
			count[i] += ((nums[j]>>i) & 1);
			count[i] = count[i] % 3;
		}
		result |= count[i] << i;
	}
	delete [] count;
	return result;
}

int main() {
	//vector<int> v = {2, 2, 3, 2};
	vector<int> v = {1};
	cout << singleNumber(v) << endl;
	return 0;
}
