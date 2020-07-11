#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cstdint>
using namespace std;
int validbyte(uint8_t d[4], int n) {
	auto is_valid = [](const uint8_t t) ->bool {
		return (t & 0xc0 ) ^ 0x80 == 0;
	};
	uint8_t data = d[0];
	if (!((data & 0xf8) ^ 0xf0)) {
		if ((n >= 4) && is_valid(d[1]) && is_valid(d[2]) && is_valid(d[3])){
			return 4;
		} 
	}
	if (!((data & 0xf0) ^ 0xe0)) {
		if ((n>=3) && is_valid(d[1]) && is_valid(d[2])){
			return 3;
		} 
	}
	if (!((data & 0xe0) ^ 0xc0)) {
		if ((n>=2) && is_valid(d[1])){
			return 2;
		} 
	}
	if (!((data & 0x80) ^ 0x00)) {
		return 1;
	}
	return 0;
}

bool validUtf8(vector<int>& data) {
	uint8_t w[4];
	for (int idx = 0; idx < data.size(); ) {
		uint8_t d = data[idx];
		w[0] = 0; w[1] = 0; w[2] = 0; w[3] = 0;
		for (int i = 0; i < 4 && idx + i < data.size(); ++i) {
			w[i] = data[idx+i];
		}
		int n = validbyte(w, data.size() - idx);
		if (n > 0) {
			idx += n;
		} else {
			return false;
		}
	}
	return true;

}


void test() {
	vector<int> data = {197, 130, 1};
	cout << validUtf8(data) << endl;
}

int main (int argc, char **argv) {
	test();
	return 0;
}
