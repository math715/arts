
#include <vector>
#include <string>
#include <iostream>
using namespace std;


bool isPalindrome(const string &str, int s, int e){
	while (s < e ){
		if (str[s] != str[e]){
			return false;
		}
		s++;
		e--;
	}
	return true;
}

void bt(string &str, int pos, vector<string> &temp, vector<vector<string>> &result){
	if (pos == str.size()){
		result.push_back(temp);
		return;
	}
	for (int s = pos ; s < str.size(); ++s){
		if (isPalindrome(str, pos, s)){
			temp.push_back(str.substr(pos, s - pos + 1));
			bt(str, s + 1, temp, result);
			temp.pop_back();
		}
	}
}


vector<vector<string>> partition(string s) {
	vector<vector<string>> result;
	vector<string> temp;
	bt(s, 0, temp, result);
	return result;
}

int main() {
	string s = "aabaa";
	auto results = partition(s);
	for (auto result : results){
		for (auto r : result){
			cout << r << " ";
		}
		cout << endl;
	}
	return 0;
}

