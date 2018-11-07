#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
bool isSquare(vector<vector<char>> &matrix, int i, int j, int k ) {
    
    int r = matrix.size();
    int c = matrix[0].size();
    for ( int a = 0; a < k; ++a) {
	for (int b = 0; b < k; ++b) {
	    assert(a+i<r && b+j<c);
	    if (matrix[a+i][b+j] != '1'){
		return false;
	    }
	}
    }
    return true;
}
int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()){
	return 0;
    }
    int r = matrix.size();
    int c = matrix[0].size();
    int result = 0;
    for  (int i = 0; i < r; ++i) {
	for (int j = 0; j < c; ++j) {
	    if (matrix[i][j] == '1') {
		result = result > 1? result : 1;
		for (int k = 2; k <= r - i && k <= c - j; ++k) {
		    if (isSquare(matrix, i, j, k)) {
			result = result > k * k ? result : k * k;
		    } else {
			break;
		    }
		}
	    }
	}
    }
    return result;


}

int main( int argc, char *argv[] ) {
    vector<vector<char>> matrix = {{'1', '0',  '1',  '0',  '0'},
	{ '1', '0', '1', '1', '1'},
	{ '1', '1', '1', '1', '1'},
	{ '1', '0', '0', '1', '0'}};
    
    cout << maximalSquare(matrix) << endl;

    return 0;
}
