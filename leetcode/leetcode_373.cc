#include <vector>
#include <set>
#include <iostream>

using namespace std;
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
		return lhs.first + lhs.second < rhs.first + rhs.second;
	};
	multiset<pair<int, int>, decltype(cmp) > ss(cmp);
	for (auto n : nums1) {
		for (auto m : nums2 ) {
			ss.insert({n,m});
		}
	}
	vector<pair<int, int>> result;
	auto it = ss.begin();
	for (int i = 0; i < k; ++i){
		if (it != ss.end()) {
			result.push_back(*it);
			++it;
		} else {
			return result;
		}
	}
	return result;

}

int main() {
	vector<int> nums1 = {1, 7, 11};
	vector<int> nums2 = {2, 4, 6};
	int k = 8;
	auto vs = kSmallestPairs(nums1, nums2, k);
	for (auto v : vs) {
		cout << v.first << " " << v.second << std::endl;
	}
	return 0;
}
