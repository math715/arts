#include <vector>
#include <string>
#include <iostream>
#include <list>
using namespace std;

void print_matrix(vector<vector<int>> &vs){
    int n = vs.size();
    cout << "************************" << endl;
    for (int i = 0; i < n; ++i){
	for (int j = 0; j < n; ++j){
	    cout << vs[i][j] << " ";
	}
	cout << endl;
    }

}
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n/2; ++i){
	int last_row = n - i -1;
	int last_col = n - i -1;
	std::list<int> s;
	//read
	for (int j = i; j < n - i; ++j){
	    s.push_back(matrix[i][j]);
	}
	for (int j = i; j < n - i; ++j) {
	    s.push_back(matrix[j][last_row]);
	}
	for (int j = n - i - 1; j >= i; --j){
	    s.push_back(matrix[last_col][j]);
	}
	for (int j = n - i - 1; j >= i; --j){
	    s.push_back(matrix[j][i]);
	}
	//write
	for (int j = i; j < n-i; ++j){
	    matrix[j][last_row] = s.front();
	    s.pop_front();
	}
	// print_matrix(matrix);
	for (int j = n - i - 1; j >= i; --j){
	    matrix[last_col][j] = s.front();
	    s.pop_front();
	}
	// print_matrix(matrix);
	for (int j = n - i - 1; j >= i; --j){
	    matrix[j][i] = s.front();
	    s.pop_front();
	}
	for (int j = i; j < n-i; ++j){
	    matrix[i][j] = s.front();
	    s.pop_front();
	}
	// print_matrix(matrix);
}

int  main() {
    vector<vector<int>> vs;
    int n = 5;
    int cnt=1;
    for (int i = 0; i < n; ++i){
	vector<int> v;
	for (int j = 0; j < n; ++j){
	    v.push_back(cnt++);
	}
	vs.push_back(v);
    }
    print_matrix(vs);
    rotate(vs);
    print_matrix(vs);
    return 0;
}
