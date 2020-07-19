#include <iostream>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	std::map<int, set<int>> table;
	for (auto vs : people) {
		table[vs[1]].insert(vs[0]);
	}

	vector<vector<int>> result;
	list<pair<int,int>> l;
	for (auto kv : table) {
		for (auto v : kv.second) {
			pair<int, int> p{v, kv.first};
			auto it = l.begin();
			int count = 0;
			for (; it != l.end(); ++it) {
				if (it->first >= v) {
					count++;
					if (count > kv.first) {
						break;
					}
				}
			}
			if (it == l.end()) {
				l.push_back(p);
			} else {
				l.insert(it,p);
			}
		}
	}
	for (auto it = l.begin(); it != l.end(); ++it) {
		vector<int> vs;
		vs.push_back(it->first);
		vs.push_back(it->second);
		result.push_back(vs);
	} 
	return result;

}
void test() {
	vector<vector<int>> people{{7,0}, {4,4}, {7, 1}, {5,0}, {6,1}, {5,2}};
	auto vs = reconstructQueue(people);
	for (auto v : vs) {
		cout << v[0] << "  =>  " << v[1] << endl;
	}
}

int main (int argc, char **argv) {
	test();
	return 0;
}
