#include <vector>
#include <iostream>
using namespace std;
int superPow(int a, vector<int>& b) {
	if (b.size() == 1) {
		int res = 1;
		for (int i = 0; i < b[0]; ++i) {
			res *= a % 1337;
			res = res % 1337;
		}
		return res;
	}
	vector<int> left;
	int r = 0;
	int frist = 0;
	for (int i = 0; i < b.size(); ++i) {
		int c = r * 10 + b[i];
		r = c & 1;
		int value = c / 2;
		if (value > 0) {
			frist = 1;
		}
		if (frist) {
			left.push_back(value);
		}
	}
	int ans = superPow(a, left);
	if (r) {
		ans = ((ans * ans) % 1337 * (a % 1337)) % 1337; 
	} else {
		ans = (ans * ans) % 1337; 
	}

	return ans;

}
int main( int argc, char **argv) {
	int a = 2;
	vector<int> b = {1, 0};
	cout << superPow(a, b) << std::endl;
	return 0;
}
