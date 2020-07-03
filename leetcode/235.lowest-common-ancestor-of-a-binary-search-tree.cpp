/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == nullptr || q == nullptr) {
            return nullptr;
        }
        int max_val = max(p->val, q->val);
        int min_val = min(p->val, q->val);
        if (root->val > max_val){
            return lowestCommonAncestor(root->left, p, q);
        } else 
        if (root->val < min_val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
        
    }
};
// @lc code=end

