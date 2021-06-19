/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }      
        int M = heights.size();
        int N = heights[0].size();
        vector<vector<bool>> a_visit(M, vector<bool>(N));
        vector<vector<bool>> p_visit(M, vector<bool>(N));
        for (int i = 0; i < M; ++i) {
            dfs(heights, a_visit, i, 0);
            dfs(heights, p_visit, i, N-1);
        }
        for (int j = 0; j < N; ++j) {
            dfs(heights, a_visit, 0, j);
            dfs(heights, p_visit, M-1, j);
        }
        vector<vector<int>> res;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (a_visit[i][j] && p_visit[i][j])  {
                    res.push_back({i, j});
                }
            }
        }
        return res;
        

    }
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visit, int i, int j){
        int M = heights.size();
        int N = heights[0].size();
        visit[i][j] = true;
        const vector<pair<int, int>> dirs  = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : dirs){
            int ii = i + dir.first;
            int jj = j + dir.second;
            if (ii >= 0 && ii < M && jj >= 0 && jj < N && !visit[ii][jj] && heights[ii][jj] >= heights[i][j]){
                dfs(heights, visit, ii, jj);
            }
        }

    }
};
// @lc code=end

