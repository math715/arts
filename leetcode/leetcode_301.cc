#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;
bool isVilad(string &s) {
	int count = 0;
	for (auto c : s) {
		if (c == ')') {
			count--;
			if (count < 0) {
				return false;
			}
		} else if (c == '(') {
			count++;
		}
	}
	return count == 0;
}
vector<string> removeInvalidParentheses(string s) {
	vector<string> res;
	queue<string> que;
	que.push(s);
	unordered_set<string> visited;
	visited.insert(s);
	bool found = false;
	while (!que.empty()) {
		for (int i = que.size(); i > 0; --i) {
			string tmp = que.front();
			que.pop();
			if (isVilad(tmp)){
				found = true;
				res.push_back(tmp);
			}
			for (int i = 0; i < tmp.size(); ++i) {
				if (tmp[i] != '(' && tmp[i] != ')'){
					continue;
				}
				string str = tmp.substr(0, i) + tmp.substr(i + 1);
				if(!visited.count(str)){
					que.push(str);
					visited.insert(str);
				}

			}
		}
		if (found) {
			break;
		}
	}
	return res;
}

int main() {
	string str = "(a)())()";
	auto vs = removeInvalidParentheses(str);
	for (auto v : vs) {
		cerr << v << endl;
	}
	return 0;
}
