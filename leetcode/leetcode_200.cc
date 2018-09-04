#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void update(vector<vector<char>> &grid, int n, int m, int i, int j) {
    const int dir[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    grid[i][j] = '2';
    for (int k = 0; k < 4; ++k){
	int r = i + dir[k][0];
	int c = j + dir[k][1];
	if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '1'){
	    grid[r][c] = '2';
	    update(grid, n, m, r, c);
	}
    }

}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    if (n == 0) {
	return 0;
    }
    int m = grid[0].size();
    int result = 0;
    for (int i = 0; i < n; ++i) {
	for (int j = 0; j < m; ++j) {
	    if (grid[i][j] == '1'){
		result++;
		update(grid, n, m, i, j);
	    }
	}
    }
    return result;

}

int main( int argc, char *argv[] ) {
    vector<vector<char>> grid;
    grid.resize(4);
    grid[0] = {'1', '1', '0', '0'};
    grid[1] = {'1', '1', '0', '0'};
    grid[2] = {'0', '0', '1', '0'};
    grid[3] = {'0', '1', '0', '1'};
    cout << numIslands(grid) << endl;

   return 0;
}
