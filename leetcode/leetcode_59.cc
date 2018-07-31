#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    int cnt = 1;
    vector<vector<int>> result;
    result.resize(n);
    for(int i = 0; i < n; ++i){
	result[i].resize(n);
    }
    for ( int i = 0; i < n / 2; ++i){
	for ( int j = i; j < n - i; ++j){
	    result[i][j] = cnt++;
	}
	for ( int j = i + 1; j < n - i; ++j){
	    result[j][n-i-1] = cnt++;
	}
	for ( int j = n - i - 2; j >= i; --j){
	    result[n-i-1][j] = cnt++;
	}
	for ( int j = n - i - 2; j > i; --j){
	    result[j][i] = cnt++;
	}
    }
    if (n & 1) {
	result[n/2][n/2] = cnt;
    }
    return result;
}

int main(){
    int n = 4;
    auto vss = generateMatrix(n);
    for (auto  &vs : vss){
	for ( auto v : vs) {
	    cout << v << " ";
	}
	cout << endl;
    }
    return 0;
}


