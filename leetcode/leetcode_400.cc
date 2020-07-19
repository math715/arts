#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int findNthDigit(int n) {
	if (n < 10) return n;
	int m = 1;
	long table[12] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000};
	long num = 9 * table[m-1] * m;
	vector<int> vs;
	while (num < n) {
		m++;
		vs.push_back(num);
		num = 9 * table[m-1] * m + num;
	}
	long t = vs.back();
	long w = n - t - 1;
	num = w / m + table[m-1];
	int idx = w % m;
	return to_string(num)[idx]-'0';
	
	
}
void test() {
	cout << findNthDigit(3) << endl;
	cout << findNthDigit(11) << endl;
	cout << findNthDigit(10) << endl;
	cout << findNthDigit(190) << endl;
	cout << findNthDigit(191) << endl;
	cout << findNthDigit(192) << endl;
for (int i = 
	cout << findNthDigit(193) << endl;
}

int main (int argc, char **argv) {
	test();
	return 0;
}
