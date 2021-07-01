/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs){
            return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
        });
        

        int ans = 0;
        int left = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < left) {
                ans++;
                left = min(left, intervals[i][1]);
            } else {
                left = intervals[i][1];
            }
        }

   
        return ans;
    }
};
// @lc code=end

