#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool isHappy(int n) {

    long _n = n;
    set<int> s;

    while (true) {
	vector<int> vs;
	while (_n > 0) {
	    vs.push_back(_n % 10);
	    _n = _n / 10;
	}
	_n = 0;
	for (auto v : vs) {
	    _n += v * v;
	}
	// cout << _n << endl;
	if (_n == 1) {
	    return true;
	} else {
	    if (s.find(_n) == s.end()){
		s.insert(_n);
	    } else {
		return false;
	    }
	}
    }
    return _n == 1;

}

int main() {
    cout << isHappy(7) << endl;
    return 0;
}
