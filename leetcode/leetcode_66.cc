#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
	vector<int> result;
	vector<int> temp = digits;
	reverse(temp.begin(), temp.end());
	int cnt = 1;
	for (auto t : temp) {
		int a = t + cnt;
		result.push_back(a % 10);
		cnt = a / 10;
	}
	if (cnt > 0 ){
		result.push_back(cnt);
	}
	reverse(result.begin(), result.end());
	return result;
}

void print_vector( vector<int> vs){
	for ( auto v : vs) {
		cout << v << " ";
	}
	cout << endl;
}


int main() {
	vector<int> t;
	t.push_back(9);
	t.push_back(9);
	t.push_back(9);
	t.push_back(9);
	// 9999 + 1;
	print_vector(plusOne(t));
	t.clear();
	// 8899 + 1;
	t.push_back(8);
	t.push_back(8);
	t.push_back(9);
	t.push_back(9);
	print_vector(plusOne(t));
	t.clear();
	// 0 + 1;
	t.push_back(0);
	print_vector(plusOne(t));
	t.clear();
	return 0;
}
