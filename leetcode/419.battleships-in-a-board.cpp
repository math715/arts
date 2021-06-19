/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */

// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
        return 0;
        }

        const int M = board.size();
        const int N = board[0].size();

        vector<vector<bool>> visited(M, vector<bool>(N));

        int res = 0;
        for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == '.' || visited[i][j]) {
                continue;
            }
            vector<pair<int, int>> idx;
            visit(board, visited, i, j, idx);
            res += IsBattleship(idx) ? 1 : 0;
            }
        }
        return res;

        }
    void visit(vector<vector<char>> &board, vector<vector<bool>> &visited, int i,
             int j, vector<pair<int, int>> &idx) {
        if (board[i][j] == '.' || visited[i][j]) {
        return;
        }
        visited[i][j] = true;
        idx.push_back({i, j});
        const int M = board.size();
        const int N = board[0].size();
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto dir : dirs) {
        int ii = i + dir.first;
        int jj = j + dir.second;
        if (ii >= 0 && ii < M && jj >= 0 && jj < N && board[ii][jj] == 'X' &&
            !visited[ii][jj]) {
            visit(board, visited, ii, jj, idx);
        }
        }
    }

    inline bool IsBattleship(vector<pair<int, int>> &idx) {
        if (idx.size() == 1) {
        return true;
        }
        int count = 0;
        for (int i = 0; i < idx.size(); ++i) {
        if (idx[0].first == idx[i].first) {
            count++;
        }
        }
        if (count == idx.size()) {
        return true;
        }
        count = 0;
        for (int i = 0; i < idx.size(); ++i) {
        if (idx[0].second == idx[i].second) {
            count++;
        }
        }
        if (count == idx.size()) {
        return true;
        }
        return false;
     }

};
// @lc code=end

