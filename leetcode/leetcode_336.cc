#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
bool Valid(string t, int left, int right) {
    while (left < right) {
	if (t[left++] != t[right--]) {
	    return false;
	}
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> result;
    unordered_map<string, int> tables;
    set<int> ss;
    for (int i = 0; i < words.size(); ++i) {
	tables[words[i]] = i;
	ss.insert(words[i].size());
    }
    for (int i = 0; i < words.size(); ++i) {
	string t = words[i];
	int len = t.size();
	reverse(t.begin(), t.end());
	if (tables.find(t) != tables.end() && tables[t] != i) {
	    result.push_back({i, tables[t]});
	}
	auto aa = ss.find(len);
	for( auto it = ss.begin(); it != aa; ++it) {
	    int d = *it;
	    if (Valid(t, 0, len - 1 - d) && tables.find(t.substr(len-d)) != tables.end()) {
		result.push_back({i, tables[t.substr(len-d)]});
	    } 
	    if (Valid(t, d, len - 1) && tables.find(t.substr(0, d)) != tables.end()) {
		result.push_back({tables[t.substr(0,d)], i});
	    }
	}
    }
    return result;
}

int main( int argc, char *argv[] ) {
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    auto vss = palindromePairs(words);
    for (auto vs : vss ) {
	for ( auto v : vs ) {
	    cout << v << " ";
	}
	cout << endl;
    }

    return 0;
}
