#include <string>
#include <iostream>
using namespace std;
//Error 超出时间限制
class Solution {
    public:
	bool isMatch(string s, string p) {
			return dp(s, p, 0, 0);
		}
	bool dp(string s, string p, int s_idx, int p_idx) {
		if (s_idx == s.size() && p_idx == p.size()) {
			return true;
		} else if (s_idx > s.size() || p_idx > p.size()) {
			return false;
		}
		if (p[p_idx] == '*') {
			int next_p = p.size();
			for (int i = p_idx + 1; i < p.size(); ++i) {
				if (p[i] != '*'){
					next_p = i;
					break;
				}
			}
			for (int i = s_idx; i <= s.size(); ++i) {
				if (dp(s, p, i, next_p)){
					return true;
				}
			}
			return false;

		} else if (p[p_idx] == '?' || p[p_idx] == s[s_idx]) {
			return dp(s, p, s_idx+1, p_idx+1);
		} else {
			return false;
		}
	}
};

class Solution2 {
    public:
		bool isMatch(string s, string p) {
			int p_idx = 0;
			int s_idx = 0;
			int ps = -1;
			int ss = -1;
			while (s_idx < s.size()) {
				// cout << p_idx << "\t" << s_idx << " " <<  p[p_idx] << "\t" << s[s_idx] << endl;
				if (p[p_idx] == s[s_idx] || p[p_idx] == '?') {
					p_idx++; s_idx++;
				} else if (p[p_idx] == '*') {
					ps = p_idx;
					ss = s_idx;
					p_idx += 1;
				} else if (ps > -1) {
					p_idx = ps + 1;
					s_idx = ss + 1;
					ss += 1;
				} else {
					return false;
				}
			}
			while(p_idx < p.size() && p[p_idx] == '*') p_idx++;
			return p_idx == p.size();
		}
	
};

// https://blog.csdn.net/hiimdaosui/article/details/51983017
// 贪心算法， 降低回溯步骤
class Solution3 {
	public :
		bool isMatch(string s, string p) {
		int ps = 0, pp = 0, lastMatch = 0, asterisk = -1;
			while (ps < s.size()) {
				// s, p当前两个字符匹配
				if (s[ps] == p[pp] || p[pp] == '?')
					ps++, pp++;
				// p的字符是星号, 记录位置, 挪动pp向后一位
				else if (p[pp] == '*')
					asterisk = pp++, lastMatch = ps;
				// 以上情况都不是, 我们返回上一次星号的位置拿星号匹配
				else if (asterisk > -1)
					ps = ++lastMatch, pp = asterisk + 1;
				// 如果之前连星号都没出现过, 直接返回不匹配
				else return false;
			}
			while (pp < p.length() && p[pp] == '*') pp++;
			return pp == p.length();
		}
};

int main () {
    string s;
    string p;
    Solution2 solu;
    s = 	"babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb";
	p =     "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
    cout << "0 " << solu.isMatch(s, p) << endl;
    return 0;
}
