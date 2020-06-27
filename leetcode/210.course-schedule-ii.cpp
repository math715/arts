/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, vector<int>> tables;
        vector<int> in_degree(numCourses, 0);
        for (int i = 0;  i < prerequisites.size(); ++i) {
                tables[prerequisites[i][1]].push_back(prerequisites[i][0]);
                in_degree[prerequisites[i][0]]++;
        }
        std::vector<int> res;
        queue<int> q;
        for ( int i = 0; i != numCourses; ++i) {
                if (in_degree[i] == 0) {
                        q.push(i);
                }
        }
        while (!q.empty()){
                int u = q.front();
                res.push_back(u);
                q.pop();
                for (int j = 0; j < tables[u].size(); ++j) {
                        int v = tables[u][j];
                        in_degree[v]--;
                        if (in_degree[v] == 0) {
                            q.push(v);
                        }
                }
        }
        if (res.size() != numCourses) {
                res.clear();
        }
        return res;

    }
};
// @lc code=end

