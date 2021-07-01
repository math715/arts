/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        bool changed = true;

        while (changed) {
            changed = false;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] != i + 1) {
                    int idx = nums[i] - 1;
                    while (nums[idx] != idx + 1) {
                        int t = nums[idx];  
                        nums[idx] = idx + 1;
                        idx = t - 1;
                        changed = true;                  
                    }     
                    nums[i] = idx + 1;                          
                }
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                ans.push_back(nums[i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

