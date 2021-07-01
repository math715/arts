/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        vector<int> w(26, 0);
        vector<int> vs(26, 0);
        for (auto c : p) {
            w[c - 'a']++;
        }
        int n = p.size();

        for (int j = 0; j < n; ++j) {
            vs[s[j]-'a']++;
        }
        vector<int> ans;
        if (vs == w) {
            ans.push_back(0);
        }
        for (int i = 1; i <= s.size() - n; ++i) {
            vs[s[i - 1] - 'a']--;
            vs[s[i + n - 1] - 'a']++;
            if (vs==w) {
                ans.push_back(i);
            }

        }
        return ans;
    }
};
// @lc code=end

