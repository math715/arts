/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
class Solution {
public:

    bool isNumber(string s) {
       	bool sign = false;
        bool num = false;
        bool dec = false;
        bool dec_num = false;
        bool exp = false;
        bool skip = false;
        bool flag = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' '){
                if (skip) {
                    return false;
                }
                flag = true;
            }
            if (s[i] == '+' || s[i] == '-') {
                if (sign || num || dec) {
                    return false;
                }
                sign = true;
            } else if (isdigit(s[i])) {
                num = true;
                if (dec) {
                    dec_num = true;
                }
            } else if (s[i] == '.') {
                if (dec || exp) {
                    return false;
                }
                dec = true;
            } else if (s[i] == 'e') {
                if (exp || num == false) {
                    return false;
                }
                exp = true;
                num = false;
                sign = false;
                dec = false;
            } else if (s[i] == ' ') {
                if (flag) {
                    skip = true;
                }
            } else {
                return false;
            }
        }
        if (dec && num == false) {
            return false;
        }
        if (exp && num == false) {
            return false;
        }
	    return flag;
    }


};
// @lc code=end

