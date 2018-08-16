#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>


using namespace std;

vector<string> dp(string s, vector<string> &wordDict, unordered_map<string, vector<string>> &hash) {
	if (hash.find(s) != hash.end()){
		return hash[s];
	}
	vector<string> ret;
	vector<string>::const_iterator it = find(wordDict.begin(), wordDict.end(), s);
	if (it != wordDict.end() ){ 
		ret.push_back(*it);
	}
	for (int i = 1; i < s.size(); ++i){
		string first = s.substr(0, i);
		if (find(wordDict.begin(), wordDict.end(), first) != wordDict.end()) {
			vector<string> vals = dp(s.substr(i), wordDict, hash);
			for (auto val : vals) {
				if (!val.empty())
				ret.push_back( first + " " + val);
			}
		}
	}
	hash[s] = ret;
	// cout << "s:" << s << endl;
	return hash[s];
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
	unordered_map<string, vector<string>> hash;
	return dp(s, wordDict, hash);

}


int main() {
	string s = "catsanddog";
	vector<string> words = {"cat", "cats", "and", "sand",  "dog"};
	/*
	string s ="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	vector<string> words = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	*/
	auto result  = wordBreak(s, words);
	for (auto r : result){
		cout << r << endl;
	}

	return 0;
}
