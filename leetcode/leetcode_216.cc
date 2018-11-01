#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
void combination(int k, int n, int level, vector<int> &out, vector<vector<int>> &result ) {
    if ( n < 0 ){
	return ;
    }
    if (n== 0 && out.size() == k) {
	result.push_back(out);
    }
    for (int i = level; i <= 9; ++i) {
	out.push_back(i);
	combination(k, n-i, i+1, out, result);
	out.pop_back();
    }

}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> out;
    combination(k, n, 1, out, result);

    return result;

}

int main( int argc, char *argv[] ) {
    int k = 9;
    int n = 45;
    auto vs = combinationSum3(k, n);

    for ( auto v : vs ){
	for (int i = 0; i < k; ++i ) {
	    cout << v[i] << "\t";
	}
	cout << endl;
    }
    return 0;
}
