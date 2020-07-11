#include <iostream>
#include <cstdint>
using namespace std;
int guess_num ;
int guess(int n) {
	if (n > guess_num) {
		return 1;
	} else if (n < guess_num) {
		return -1;
	}
	return 0;
}
int guessNumber(int n) {
	int m = n;
	int status = guess(n);
	long num = n;
	while (status < 0) {
		if (num > INT32_MAX) {
			num = INT32_MAX;
		}
		status = guess(num);
		num *= 2;
	}
	int prev = num / 2;
	while (status != 0) {
		if (status == 1) {
			num = num - prev;
		} else if (status == -1) {
			num = num + prev;
		}
		prev = prev/2;
		if (prev == 0) {
			prev = 1;
		}
		status = guess(num);
	}
	return num;      
}

void Test(int n, int t) {
	guess_num = t;
	int m = guessNumber(n);
	cout << m << " " << t << endl;
}

int main() {
	int n = 10;
	int t = 6;
	Test(n, t);
	n = 10;
	t = 9;
	Test(n, t);
	n = 30;
	t = 117;
	Test(n, t);
}
