#include <vector>
#include <iostream>

using namespace std;
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = dungeon.size();
    int m = dungeon[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,INT32_MAX));
    dp[n-1][m] = 1;
    for (int i = n - 1; i >= 0; --i) {
	for (int j = m - 1; j >= 0; --j) {
	    int val = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
	    dp[i][j] = max(val, 1);
	}
    }
    return dp[0][0];

}

int main() {
    vector<vector<int>> dungeon;
    dungeon.resize(3);
    dungeon[0].push_back(-2);
    dungeon[0].push_back(-3);
    dungeon[0].push_back(3);
    dungeon[1].push_back(-5);
    dungeon[1].push_back(-10);
    dungeon[1].push_back(1);
    dungeon[2].push_back(10);
    dungeon[2].push_back(30);
    dungeon[2].push_back(-5);
    cout  << calculateMinimumHP(dungeon) << endl;
    return 0;

}
