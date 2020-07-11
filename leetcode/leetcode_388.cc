#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

int lengthLongestPath(string  input) {
	if (input.empty()) {
		return 0;
	}
	string line;
	string temp;
	bool last = false;
	auto is_file = [](const string &s) -> bool {
		auto pose = s.find('.');
		return pose != string::npos;
	};
	auto number = [](const string &s) -> int {
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] != '\t') {
				return i;
			}
		}
		return s.length();
	};

	int res = 0, len;
	stack<pair<int, int>> st;
	temp = input;
	while (true) {
		auto pose = temp.find('\n');
		if (pose != std::string::npos) {
			line = temp.substr(0, pose);
			temp = temp.substr(pose+1);
		} else {
			last = true;
			line = temp;
		}
		int num = number(line);
		len = line.length() - num;
		if (is_file(line)) {
			while( num < st.size() && !st.empty()) {
				st.pop();
			}
			if (st.empty()){
				res = len > res ? len : res;
			} else {
				auto top = st.top();
				res = top.second + len > res ? top.second + len : res;
			}
		} else {
			while( num < st.size() && !st.empty()) {
				st.pop();
			}
			if (st.empty()) {
				st.push(pair<int, int>(len, len+1));
			} else {
				auto top = st.top();
				int w = top.second + len + 1;
				st.push(pair<int, int>(len, w));
			}
		}
		if (last) {
			break;
		}	
	}
	return res;
}

void test(string case1) {
	cout << lengthLongestPath(case1) << endl;
}

int main (int argc, char **argv) {
	string case1; 
	case1 = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	test(case1);
	case1 = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
	test(case1);
	case1 = "dir\n    file.txt";
	test(case1);

	return 0;
}
