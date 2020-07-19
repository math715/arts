#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


int trapRainWater(vector<vector<int>>& heightMap) {
	int result = 0;
	int m = heightMap.size();
	if (m == 0) {
		return result;
	}
	int n = heightMap[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	int dir[4][2] = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}};
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == 0 || j == 0 || i == m-1 || j == n - 1) {
				q.push({heightMap[i][j], i * n + j});
				visited[i][j] = true;
			}
		}
	}
	int mx = INT32_MIN;
	while (!q.empty()) {
		auto top = q.top();
		q.pop();
		int h = top.first;
		int r = top.second / n;
		int c = top.second % n ;
		mx = max(mx, h);
		for (int i = 0; i < 4; ++i) {
			int x = r + dir[i][0];
			int y = c + dir[i][1];
			if (x <= 0 || y <= 0 || x >= m-1 || y >= n - 1 || visited[x][y]) {
				continue;
			}
			visited[x][y] = true;
			if (heightMap[x][y] < mx) {
				result += mx - heightMap[x][y];
			}
			q.push({heightMap[x][y], x * n + y});
		}

	}

	return result;
}
void test() {
	vector<vector<int>> vs = 
	{{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}}
	;
	cout << trapRainWater(vs) << endl;
}


int main (int argc, char **argv) {
	test();
	return 0;
}
