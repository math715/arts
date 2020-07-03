#include <vector>
#include <iostream>
using namespace std;
vector<int> getMaxNums(vector<int> &nums, int k) {
	if (k == nums.size()){
		return nums;
	}
	int prev = 0;
	vector<int> res;
	while(k > 0 ){
		int value = nums[prev];
		for (int i = prev+1; i  + k <= nums.size();++i) {
			if (nums[i] > value) {
				prev = i;
				value = nums[i];
			}
		}
		res.push_back(value);
		prev = prev + 1;
		k--;
	}
	return res;
}
bool compare(vector<int> &s, int i, vector<int> &t, int j) {
	int s_idx = i;
	int t_idx = j;
	while (true) {
		if (s_idx >= s.size()) {
			return false;
		}
		if (t_idx >= t.size()) {
			return true;
		}
		if (s[s_idx] > t[t_idx]) {
			return true;
		} else if ( s[s_idx] < t[t_idx]) {
			return false;
		} else {
			s_idx++;
			t_idx++;
		}
	}
}
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	vector<int> res;
	vector<vector<int>> temp_res;
	for (int i = 0; i < k; ++i) {
		if ( i <= nums1.size() && k - i <= nums2.size()) {
			auto max_nums1 = getMaxNums(nums1, i);	
			auto max_nums2 = getMaxNums(nums2, k - i);	
			int m = 0, n = 0;
			vector<int> tmp;
			while ( !(m == max_nums1.size() && n == max_nums2.size())) {
				if (m == max_nums1.size() ){
					for ( int w = n; w < max_nums2.size(); ++w) {
						tmp.push_back(max_nums2[w]);
					}
					n = max_nums2.size();
				} else if (n == max_nums2.size()) {
					for ( int w = m; w < max_nums1.size(); ++w) {
						tmp.push_back(max_nums1[w]);
					}
					m = max_nums1.size();
				} else {
					if (max_nums1[m] > max_nums2[n]) {
						tmp.push_back(max_nums1[m]);
						m++;
					} else if (max_nums1[m] == max_nums2[n]) {
						if (compare(max_nums1, m, max_nums2, n)) {
							tmp.push_back(max_nums1[m]);
							m++;
						} else {
							tmp.push_back(max_nums2[n]);
							n++;
						}
					} else {
						tmp.push_back(max_nums2[n]);
						n++;
					}
				}

			}
			temp_res.push_back(tmp);
		}
	}
	vector<int> flag;
	flag.resize(temp_res.size());
	for (int j = 0; j < temp_res.size(); ++j) {
		flag[j] = 0;
	}
	for (int i = 0; i < k; ++i) {
		int max_value = -1;
		for (int j = 0; j < temp_res.size(); ++j) {
			if (!flag[j]){
				if (temp_res[j][i] >= max_value){
					max_value = temp_res[j][i];
				}
			}
		}
		for (int j = 0; j < temp_res.size(); ++j) {
			if (!flag[j]){
				if (temp_res[j][i] < max_value){
					flag[j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < temp_res.size(); ++i) {
		if (!flag[i]){
			res = temp_res[i];
			break;
		}
	}
	return res;
}

int main() {
	{
		vector<int> nums1 = {3, 4, 6, 5};
		vector<int> nums2 = {9, 1, 2, 5, 8, 3};
		int k = 5;
		auto res = maxNumber(nums1, nums2, k);
		for (auto v : res) {
			cout << v << " " ;
		}
		cout << endl;
	}
	{
	vector<int> nums1 = {6, 7};
	vector<int> nums2 = {6, 0, 4};
	int k = 5;
	auto res = maxNumber(nums1, nums2, k);
	for (auto v : res) {
		cout << v << " " ;
	}
	cout << endl;
	}
	{
	vector<int> nums1 = {2,5,6,4,4,0};
	vector<int> nums2 = {7,3,8,0,6,5,7,6,2};
	int k = 15;
	auto res = maxNumber(nums1, nums2, k);
	for (auto v : res) {
		cout << v << " " ;
	}
	cout << endl;
	}
	return 0;
}
