#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) {
	return false;
    }
    int n = matrix[0].size();
    if ( m == 0 || n == 0){
	return false;
    }
    int i = m - 1 ;
    int j = 0;
    bool f;
    while (true) {
	if (matrix[i][j] < target){
	    if (j < n -1) {
		j += 1;
	    } else {
		return false;
	    }
	} else if (matrix[i][j] > target) {
	    if (i > 0) { 
		i -= 1;
	    } else {
		return false;
	    }
	} else {
	    return true;
	}
    }
}

int main( int argc, char *argv[] ) {
    vector<vector<int>> matrix;
    vector<int> a1 = {1,   4,  7, 11, 15};
    vector<int> a2 = {2,   5,  8, 12, 19};
    vector<int> a3 = {3,   6,  9, 16, 22};
    vector<int> a4 = {10, 13, 14, 17, 24};
    vector<int> a5 = {18, 21, 23, 26, 30};
    matrix.push_back(a1);
    matrix.push_back(a2);
    matrix.push_back(a3);
    matrix.push_back(a4);
    matrix.push_back(a5);
    cout << searchMatrix(matrix, 26);

    return 0;
}
