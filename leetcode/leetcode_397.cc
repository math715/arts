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

int integerReplacement(int n) {
	if (n == 1) {
		return 0;
	}	
	if (n % 2 == 0) {
		return 1 + integerReplacement(n/2);
	} else {
		return 1 + min(integerReplacement(n+1), integerReplacement(n-1));
	}
}
void test() {
	cout << integerReplacement(8) << endl;
	cout << integerReplacement(7) << endl;
}

int main (int argc, char **argv) {
	test();
	return 0;
}
