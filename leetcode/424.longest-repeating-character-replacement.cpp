/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        vector<int> tmp(26,0);
        int res=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            tmp[s[i]-'A']++;
            int count=*max_element(tmp.begin(),tmp.end());
            while(i-start+1-count>k)
            {
                tmp[s[start]-'A']--;
                count=*max_element(tmp.begin(),tmp.end());
                start++;
            }
            res=max(res,i-start+1);
        }
        return res;
    }
};
// @lc code=end

