/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 1; i <=n; ++i) {
            if (p[i-1] == '*') {
                dp[0][i] = dp[0][i-1];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else {
                    dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?')  && dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }   
};
// @lc code=end

