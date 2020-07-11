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
int longestSubstring(string s, int k) {
	if (s.length() < k) {
		return 0;
	}
	cout << "s " << s << endl;
	int w[26] = {0};
	for (int i = 0; i < s.length(); ++i) {
		w[s[i] - 'a']++;
	}
	int start = 0;
	while (start < s.length() && w[s[start] - 'a'] < k) {
		start++;
	}
	int end = s.length() - 1;
	while (end >= 0 && w[s[end] - 'a'] < k) {
		end--;
	}
	if (end - start + 1 < k) {
		return 0;
	}
	int res = 0;
	for (int i = start; i <= end; ++i) {
		if (w[s[i]-'a'] < k) {
			string t1 = s.substr(start, i - start);
			string t2 = s.substr(1+i, end - start + 1);	
			cout << t1 << " " << t2 << endl;
			return max(longestSubstring(t1, k), longestSubstring(t2,k));
		}	
	}
	return end - start + 1;
}


void test() {
	{
		string s = "bbaaacbd";
		int k = 3;
		cout << longestSubstring(s, k) << endl;

	}


}

int main (int argc, char **argv) {
	test();
	return 0;
}
