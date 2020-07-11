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

  char findTheDifference(string s, string t) {
        int a[26] = {0};
        for (auto ch : s) {
            a[ch-'a']++;
        }
        for (auto ch : t) {
            a[ch-'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (a[i] != 0) {
                return i + 'a';
            }
        }
        return 'a';
    }
void test(string s, string t) {
	cout << s << "\t" << t << " " << findTheDifference(s, t) << endl;;
}

int main (int argc, char **argv) {
	string s, t;
	s = "abcd";
	t = "abcde";
	test(s, t);
	return 0;
}
