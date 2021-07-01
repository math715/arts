/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        std::vector<int> values;
        int ans = 0;
        unordered_map<long, int> table;
        table[0] = 1;
        long cur_sum = 0;
        DFS(root, table, cur_sum, targetSum, ans);
        return ans;

    }
    void DFS(TreeNode *node, unordered_map<long, int>& table, long cur_sum , int sum, int &ans) {
        if (!node) {
            return ;
        }
        cur_sum += node->val;
        if (table.find(cur_sum  - sum) != table.end()){
            ans += table[cur_sum - sum];
        }
        table[cur_sum]++;
        DFS(node->left, table, cur_sum, sum, ans);
        DFS(node->right, table, cur_sum, sum , ans);
        table[cur_sum]--;
    }
};
// @lc code=end

