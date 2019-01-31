#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &m , vector<vector<int>> &dp, int i, int j, int row, int col) {
    if (dp[i][j] > 0) {
	return dp[i][j];
    }
    int left = 1, right = 1, up = 1, down = 1;
    if (i > 0 && m[i-1][j] > m[i][j]) {
	up = 1 + dfs(m, dp, i-1, j, row, col); 
    }
    if (i < row - 1 && m[i+1][j] > m[i][j]) {
	down = 1 + dfs(m, dp, i+1, j, row, col);
    }
    if (j > 0 && m[i][j-1] > m[i][j]) {
	left = 1 + dfs(m, dp, i, j-1, row, col);
    }
    if (j < col - 1 && m[i][j+1] > m[i][j]) {
	right = 1 + dfs(m, dp, i, j+1, row, col);
    }
    dp[i][j] = max(max(up, down), max(left, right));
    return dp[i][j];

}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if (row == 0) {
	return 0;
    }
    int col = matrix[0].size();

    int ans = 0;
    vector<vector<int>> dp(row, vector<int>(col, 0)); 
    for (int i = 0; i < row; ++i) {
	for (int j= 0; j < col; ++j) {
	    ans = max(dfs(matrix, dp, i, j, row, col) , ans);
	}
    }
    return ans;

}

int main( int argc, char *argv[] ) {

    // vector<vector<int>> matrix = { {9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    vector<vector<int>> matrix = { {1, 2}}; 

    cout << longestIncreasingPath(matrix) << endl;

    return 0;
}
