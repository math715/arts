#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


bool wordBreak(string s, vector<string>& wordDict) {
	vector<int> results;
	results.resize(s.size() + 1, 0);
	results[0] = 1;
	for (int i = 1; i <= s.size(); ++i){
		for (int j = i - 1; j >= 0; --j){
			if (results[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
				results[i] = 1;
				break;
			}
		}
	}
	return results[s.size()];

}


int main() {
	   string s = "leetcode";
	   vector<string> words = {"leet", "code"}; 
	   cout << wordBreak(s, words) << endl;

	   /*
	   string s = "catsanddog";
	   vector<string> words = {"cats", "dog", "sand", "and", "cat"};
	   cout << wordBreak(s, words) << endl;
	string s ="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	vector<string> words = {"aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"};
	cout << wordBreak(s, words) << endl;
	   */
	return 0;
}
