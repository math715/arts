/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        if (intervals.size() == 1) {
            return {-1};
        }
        map<int, int> table;
        for (int i = 0; i < intervals.size(); ++i) {
            table[intervals[i][0]] = i;
        }
        std::vector<int> ans;
        for (int i = 0; i < intervals.size(); ++i) {
            auto iter = table.lower_bound(intervals[i][1]);
            if (iter != table.end()){
                ans.push_back(iter->second);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;

    }
};
// @lc code=end

