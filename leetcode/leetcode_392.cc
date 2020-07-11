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

bool isSubsequence(string s, string t) {
	int last = 0;
	for (auto c : s) {
		while (t.length() > last && t[last] != c ) {
			last++;
		}
		if (t[last] == c) {
			last++;
		} else {
			return false;
		}
	}
	return true;
}
void test() {
	cout << isSubsequence("abx", "ab");
}

int main (int argc, char **argv) {
	test();
	return 0;
}
