#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

string sort_str(string str){
     sort(str.begin(), str.end());
     return str;
}
vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    map<string, int> idx;
    int id;
    for (auto &str : strs) {
	string sstr = sort_str(str);
	if (idx.find(sstr) != idx.end()){
	    id = idx[sstr];
	} else {
	    id = result.size();
	    idx[sstr] = id;
	    vector<string> v;
	    result.push_back(v);
	}
	result[id].push_back(str);
    }
    return result;
}


int main() {
    // vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs = {"eata", "atea", "tan", "atea", "nat", "bat"};
    auto results = groupAnagrams(strs);
    for( auto result : results) {
	for (auto r : result){
	    cout << r << " ";
	}
	cout << endl;
    }

    return 0;
}
