#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
bool wordPattern(string pattern, string str) {
	vector<string> vec;
	int prev = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == ' ') {
			vec.push_back(str.substr(prev, i - prev));
			prev = i + 1;
		}
	}
	vec.push_back(str.substr(prev));
	unordered_map<char, string> table;
	unordered_map<string, char> map;
	for (int i = 0; i < pattern.size(); ++i) {
		if (table.find(pattern[i]) == table.end()){
			table[pattern[i]] = vec[i];
		} else {
			auto value = table[pattern[i]];
			if (value != vec[i]){
				return false;
			}
		}
		if (map.find(vec[i]) == map.end()){
			map[vec[i]] = pattern[i];
		} else {
			auto value = map[vec[i]];
			if (value != pattern[i]){
				return false;
			}
		}
	}
	return true;
}
int main() {
	cout << wordPattern("abba", "dog cat cat dog") << endl;
	cout << wordPattern("abba", "dog dog dog dog") << endl;
	return 0;
}
