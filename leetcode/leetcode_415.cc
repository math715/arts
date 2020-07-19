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

string addStrings(string num1, string num2) {

	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	int m1 = num1.length();
	int m2 = num2.length();
	int i = 0;
	string r;
	for (int j = 0; j < max(m1, m2); ++j) {
		char c;
		int w;
		if (j < m1 && j < m2) {
			w = (num1[j] - '0') + (num2[j] - '0') + i;
		} else if ( j < m1) {
			w = (num1[j] - '0')  + i;
		} else if (j < m2){
			w = (num2[j] - '0')  + i;
		}
		i = w / 10; 
		c = (w % 10) + '0';	
		r.push_back(c);
	}
	if (i>0) {
		r.push_back('1');
	}
	reverse(r.begin(), r.end());
	return r;
}

void test() {
	string num1, num2;
	num1 = "99";
	num2 = "1";
	cout << addStrings(num1, num2) << endl;
	num1 = "9";
	num2 = "991";
	cout << addStrings(num1, num2) << endl;
	num1 = "1000988";
	num2 = "991";
	cout << addStrings(num1, num2) << endl;
	
}

int main (int argc, char **argv) {
	test();
	return 0;
}
