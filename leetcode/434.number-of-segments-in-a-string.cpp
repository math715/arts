/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int last = -1;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (!isspace(s[i])) {
                last = i;            
            } 
            if (last != -1 && i > last && isspace(s[i])) {
                ans++;
                last = -1; 
            }
        }
        if (last == s.size() - 1 && last != -1) {
            ans++;
        }
        return ans;

    }
};
// @lc code=end

