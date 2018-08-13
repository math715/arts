
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


void flip(vector<vector<char>> &board, int i , int j ){
	/*
	int n = board.size();
	int m = board[0].size();
	vector<pair<int, int>> records;
	queue<pair<int, int>> que;
	pair<int, int> p = {i,j};
	que.push(p);
	bool result = true;
	while(!que.empty()){
		auto rec = que.front();
		que.pop();
		records.push_back(rec);
		board[rec.first][rec.second] = 'A';
		for (i = 0; i < 4; ++i){
			int row = rec.first + dir[i].first;
			int col = rec.second + dir[i].second;
			if (row < 0 || row >= n || col < 0 || col >= m){
				result = false;
				break;
			}
			if (board[row][col] == 'O' ){
				pair<int, int> p = {row, col};
				que.push(p);
			} else if (board[row][col] == 'B' ){
				result = false;
				break;
			}
			
		}
	}
	if (result){
		for (auto rec : records) {
			board[rec.first][rec.second] = 'X';
		}
	} else {
		for (auto rec : records) {
			board[rec.first][rec.second] = 'B';
		}
	}
	*/

}

void dfs(vector<vector<char>> &board, const vector<pair<int, int>> &dir, int i, int j){
	int n = board.size();
	int m = board[0].size();
	board[i][j] = 'A';
	for (int d = 0; d < 4; ++d){
		int row = i + dir[d].first;
		int col = j + dir[d].second;
		if (row >= 0 && row < n && col >= 0 && col < m && board[row][col] == 'O'){
			dfs(board, dir, row, col);
		}
	}


}
void solve(vector<vector<char>>& board) {
	if (board.empty()){ 
		return ;
       	}
       	int n = board.size();
	int m = board[0].size();
	const vector<pair<int, int>> dir = { {-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1){
				if (board[i][j] == 'O'){
					dfs(board, dir, i, j);
				}
			}
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (board[i][j] == 'O') {
				board[i][j] = 'X';
			}
			if (board[i][j] == 'A'){
				board[i][j] = 'O';
			}
		}
	}
}

int main() {
	vector<vector<char>> board;
	solve(board);
	vector<string> test1 = { "XXXX", "XOOX", "XXOX", "XOXX" };
	// vector<string> test1 = { "OO","OO"};
	for (int i = 0; i < test1.size(); ++i){
		vector<char> t;
		for (int j = 0; j < test1[i].size(); ++j){
			t.push_back(test1[i][j]);
		}
		board.push_back(t);
	}
	solve(board);
	for (auto vs : board){
		for (auto v : vs){
			cout << v;
		}
		cout << endl;
	}
	return 0;

}

