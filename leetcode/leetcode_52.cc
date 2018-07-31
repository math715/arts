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
void find(int depth, int n, vector<int> res, int &result){
    if (depth == n){
	result++;
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

int totalNQueens(int n) {
    vector<int> res;
    int result = 0;
    find(0, n, res, result);
    return result;
}
int main() {
    int n = 4;
    int result = totalNQueens(n);
    cout << result << endl;


}
