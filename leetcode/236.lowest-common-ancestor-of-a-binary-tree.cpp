/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
        unordered_map<TreeNode*,TreeNode*> fa;
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> que;
        if(root) que.push(root);
        fa[root] = nullptr;
        while(que.size()){
            TreeNode* par = que.front();
            que.pop();
            if(par->left){
                que.push(par->left);
                fa[par->left] = par;
            }
            if(par->right){
                que.push(par->right);
                fa[par->right] = par;
            }
        }
        while(p){
            vis.insert(p);
            p = fa[p];
        }
        while(q){
            if(vis.count(q)){
                return q;
            }
            q = fa[q];
        }
        return nullptr;
    }
};
// @lc code=end

