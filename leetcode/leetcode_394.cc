#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
string decodeString(string s) {
	string result;
	stack<pair<string, string>> st;
	string temp;
	string num;
	string value;
	auto to_string = [](const pair<string, string> &p) {
		std::cerr << p.first << " => " << p.second << std::endl;
		int num = stoi(p.first);
		string s;
		for (int i = 0; i < num; ++i) {
			s+= p.second;
		}
		return s;
	};

	int value_count = 0;
	bool have_digit = false;
	for	(int i = 0; i < s.length(); ++i) {
		if (s[i] == ']') {
			string w;
			pair<string, string> p{num,value};
			w = to_string(p);
			if (!st.empty()) {
				auto top = st.top();
				st.pop();
				num = top.first;
				value = top.second + w;
			} else {
				result += w;
				num.clear();
				value.clear();
			}
			value_count--;
		} else if (s[i] == '[') {
			value.clear();
			value_count++;
			have_digit = false;
		} else if (isdigit(s[i])) {
			if (have_digit) {
				num += s[i];
			} else {
				have_digit = true;
				if (!num.empty()) {
					pair<string, string> p(num, value);
					st.push(p);
				}
				num.clear();
				num += s[i];
			}
		} else {
			if (value_count > 0) {
				value += s[i];
			} else {
				result += s[i];
			}
		}

	}
	return result;
}

void test() {
/*
	std::cout << decodeString("2[a]") << std::endl;
	std::cout << decodeString("d2[a2[c]]") << std::endl;
	std::cout << decodeString("d2[a2[c]d]") << std::endl;
*/
	std::cout << decodeString("d2[2[a]d3[c]]") << std::endl;
}

int main (int argc, char **argv) {
	test();
	return 0;
}
