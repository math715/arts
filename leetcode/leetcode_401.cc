#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
using namespace std;
vector<string> ToHour(const int table[60], int n) {
	vector<string> result;
	for (int i = 0; i < 12; ++i) {
		if (table[i] == n) {
			result.push_back(to_string(i));
		}
	}
	return result;
}
vector<string> ToMinutes(const int table[60], int n) {
	vector<string> result;
	for (int i = 0; i < 60; ++i) {
		if (table[i] == n) {
			ostringstream oss;
			oss <<  setfill('0') << setw(2) << i;
			result.push_back(oss.str());
		}
	}
	return result;
}
vector<string> readBinaryWatch(int num) {
	int table[60] = {0};
	for (int i = 0; i < 60; ++i) {
		int count = 0;
		int w = i;
		while(w) {
			count += (w & 1);
			w >>= 1;
		}
		table[i] = count;
	}
	vector<string> result;
	for (int i = 0; i <= num; ++i) {
		auto hours = ToHour(table, i);
		auto minutes = ToMinutes(table, num-i);
		if (hours.empty() || minutes.empty()) {
			continue;
		}
		for (auto h : hours) {
			for (auto m : minutes) {
				result.push_back(h + ":" + m);
			}
		}


	}
	return result;

}

void test() {
{
	auto vs = readBinaryWatch(0);
	for (auto v : vs) {
		cout << v << " " ;
	}
	cout <<endl;
}
	auto vs = readBinaryWatch(0);
	for (auto v : vs) {
		cout << v << " " ;
	}
	cout <<endl;
}

int main (int argc, char **argv) {
	test();
	return 0;
}
