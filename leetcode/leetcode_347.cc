#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> tables;
    for (auto num : nums) {
	if (tables.find(num) != tables.end()){
	    tables[num]++;
	} else {
	    tables[num] = 1;
	}
    }
    vector<int> result;
    multimap<int, int, std::greater<int>> hashtables;
    for (auto p : tables) {
	hashtables.insert( make_pair(p.second, p.first));
    }
    int cnt = 0;
    for (auto p : hashtables) {
	if (cnt <  k) {
	    result.push_back(p.second);
	} else {
	    break;
	}
	cnt++;
    }
    return result;
}

int main( int argc, char *argv[] ) {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k  = 2;
    auto vs = topKFrequent(nums, k);
    for (auto v : vs ) {
	cout << v << " ";
    }
    cout << endl;

    return 0;
}
