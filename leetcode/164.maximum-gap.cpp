/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int max_num = nums[0], min_num = nums[0];
        for (auto num : nums) {
            if (max_num < num ) max_num = num;
            if (min_num > num ) min_num = num;
        }

        int len = (max_num - min_num) / nums.size() + 1;
        vector<vector<int>> buckets((max_num - min_num) / len + 1);
        for (auto num : nums) {
            int idx = (num - min_num) / len ;
            if (buckets[idx].empty()) {
                buckets[idx].reserve(2);
                buckets[idx].push_back(num);
                buckets[idx].push_back(num);
            } else {
                if (buckets[idx][0] > num) {
                    buckets[idx][0] = num;
                }
                if (buckets[idx][1] < num) {
                    buckets[idx][1] = num;
                }
            }
        }
        int gap = 0;
        int prev = 0;
        for (int i = 1; i < buckets.size(); ++i){
            if (buckets[i].empty()) continue;
            gap = max(gap, buckets[i][0] - buckets[prev][1]);
            prev = i;
        }
        return gap;
    }
};
// @lc code=end

