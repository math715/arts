/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {

        queue<std::pair<Node*, int>> que;
        que.push({root, 0});
        vector<vector<int>>  ans;
        vector<int> vs;
        int level = 0;
        while (!que.empty()) {
            auto kv = que.front();
            que.pop();
            if (kv.second != level) {
                level = kv.second;
                ans.push_back(vs);
                vs.clear();
            }
            if (kv.first == nullptr) {
                continue;
            }
            vs.push_back(kv.first->val);
            for (auto node : kv.first->children) {
                que.push({node, kv.second + 1});
            }
        }
        if (!vs.empty()) {
            ans.push_back(vs);
        }
        return ans;

    }
};
// @lc code=end

