#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> split(string version) {
	vector<int> results;
	istringstream f(version);
	string s;
	while(getline(f, s, '.')) {
		results.push_back(stoi(s));
	}
	return results;
}

int compareVersion(string version1, string version2) {
	vector<int> vs1 = split(version1);
	vector<int> vs2 = split(version2);
	if (vs1.size() > vs2.size()){
		int n = vs1.size() - vs2.size();
		for (int i = 0; i < n; ++i) {
			vs2.push_back(0);
		}
	} else {
		int n = vs2.size() - vs1.size();
		for (int i = 0; i < n; ++i) {
			vs1.push_back(0);
		}
	}
	int i;
	for ( i = 0; i < vs1.size(); ++i) {
		if (vs1[i] > vs2[i]) {
			return 1;
		} else if (vs1[i] < vs2[i]) {
			return -1;
		} else {
			;
		}
	}
	return 0;

}

int main() {
	string v1 = "5.6.7.0.0";
	string v2 = "5.6.7";
	cout << compareVersion(v1, v2) << endl;;
	return 0;
}
