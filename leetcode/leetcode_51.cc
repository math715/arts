#include <vector>
#include <string>
#include <iostream>

using namespace std;
bool solve(vector<int> &res) {
    int size = res.size();
    auto p = res[size-1];
    for (int j = 0; j < size - 1; ++j){
	auto q = res[j];
	if (p == q || ( size - 1 - j) == (p - q > 0 ? p - q : q - p)){
	    return false;
	} 
    }
    return true;
}
vector<string> res_string(vector<int> &res , int n) {
    vector<string> result;
    for (int i = 0; i < n ; ++i) {
	string str;
	for (int j = 0; j < n; ++j) {
	    if (res[i] == j){
		str.push_back('Q');
	    } else {
		str.push_back('.');
	    }
	}
	result.push_back(str);
    }
    return result;
}

void find(int depth, int n, vector<int> res, vector<vector<string>> &result){
    if (depth == n){
	auto str = res_string(res, n);
	result.push_back(str);
	return ;
    }
    for (int i = 0; i < n ; ++i){
	vector<int> ress = res;
	ress.push_back(i);
	if (solve(ress)){
	    find(depth+1, n, ress, result);
	}
    }
}



vector<vector<string>> solveNQueens(int n) {
    vector<int> res;
    vector<vector<string>> results;
    find(0, n, res, results);
    return results;
}
int main() {
    int n = 4;
    auto results = solveNQueens(n);
    for (auto result : results) {
	for (auto s : result ){
	    cout << s << endl;
	}
	cout << endl;
    }

}
