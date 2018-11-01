#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool search(vector<vector<char>> &board, int i, int j, const string &word, int idx){
    if (idx == word.size()) {
	return true;
    }
    const int a[4] = {1, -1, 0, 0};
    const int b[4] = {0, 0, -1, 1};
    int r = board.size();
    int c = board[0].size();
    for (int d = 0; d < 4; ++d) {
	int dx = i + a[d];
	int dy = j + b[d];
	if (dx >= 0 && dy >= 0 && dx < r && dy < c && board[dx][dy] != '*'){
	    if (board[dx][dy] == word[idx]) {
		char temp = board[dx][dy];
		board[dx][dy] = '*';
		if (search(board, dx, dy, word, idx+1)){
		    return true;
		}
		board[dx][dy] = temp;
	    }
	}
    }
    return false;
}

bool findWord(const vector<vector<char>> &board, const string &word) {
    int r = board.size();
    int c = board[0].size();
    vector<vector<char>> temp = board;
    for (int i = 0; i < r; ++i) {
	for (int j = 0; j < c; ++j) {
	    if( board[i][j] == word[0]) {
		char t = temp[i][j] ;
		temp[i][j] = '*';
		if (search(temp, i, j, word, 1)) {
		    return true;
		}
		temp[i][j] = t;
	    }
	}
    }
    return false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    set<string> rs;
    for (auto &word : words) {
	if (findWord(board, word)) {
	    rs.insert(word);
	}
    }
    vector<string> result;
    for (auto &r : rs ){
	result.push_back(r);
    }
    return result;

}

int main( int argc, char *argv[] ) {
    /*
    vector<vector<char>> board = {
	{'o','a','a','n'},
	{'e','t','a','e'},
	{'i','h','k','r'},
	{'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    */
    vector<vector<char>> board = {{'a'}};
    vector<string> words = {"a", "a"};
    auto rs = findWords(board, words);
    cout << rs.size() << endl;
    for (auto r : rs ){
	cout << r << endl;
    }

    return 0;
}
