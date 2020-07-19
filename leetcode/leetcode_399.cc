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
bool Find(unordered_map<string, unordered_map<string, double>> &table, vector<string> &query, double &value, unordered_set<string> s) {
	string a = query[0];
	string b = query[1];
	if (table.find(a) != table.end() && table.find(b) != table.end()) {
		if (a == b) {
			value = 1.0;
			return true;
		}
		auto &m = table[a];
		if (m.find(b) != m.end()) {
			value = m[b];
			return true;
		} else {
			s.insert(a);
			for ( auto kv : m) {
				if (s.find(kv.first) != s.end()) {
					continue;
				}
				vector<string> q, p;
				q.push_back(a);
				q.push_back(kv.first);
				p.push_back(kv.first);
				p.push_back(b);
				double c, d;
				if (Find(table, q, c, s) && Find(table, p, d, s)){
					value = c * d;
					return true;	
				}
			}
			value = -1.0;
			return false;
		}
	} else {
		value = -1.0;
		return false;
	}
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	unordered_map<string, unordered_map<string, double>> table;
	for (int i = 0; i < equations.size(); ++i) {
		auto equation = equations[i];
		auto &a = equation[0];
		auto &b = equation[1];
		if (table.find(a) != table.end()) {
			auto &m = table[a];
			m[b] = values[i];
		} else {
			unordered_map<string, double> m;
			m[b] = values[i];
			table[a] = m;
		}
		if (table.find(b) != table.end()) {
			auto &m = table[b];
			m[a] = 1/values[i];
		} else {
			unordered_map<string, double> m;
			m[a] = 1/values[i];
			table[b] = m;
		}
	}
	vector<double> result;
	for (int i = 0; i != queries.size(); ++i) {
		double value; 
		unordered_set<string> s;
		if (Find(table, queries[i], value, s)){
			result.push_back(value);
		} else {
			result.push_back(-1.0);
		}
	}
	return result;

}

void test() {
	{
		vector<vector<string>> equations{{"a", "b"}, {"b", "c"}};
		vector<double> values{2.0, 3.0};
		vector<vector<string>> queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
	}
	{
		vector<vector<string>> equations{{"x1","x2"},{"x2","x3"},{"x3","x4"},{"x4","x5"}};
		vector<double> values{3.0,4.0,5.0,6.0};
		// vector<vector<string>> queries{{"x1","x5"},{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}};
		vector<vector<string>> queries{{"x5","x2"}};
// ,{"x5","x2"},{"x2","x4"},{"x2","x2"},{"x2","x9"},{"x9","x9"}};
		vector<double> vs = calcEquation(equations, values, queries);
		std::cout << vs.size() << std::endl;
		for (auto v : vs) {
			cout << v << " ";
		}
		cout << endl;
	}


}

int main (int argc, char **argv) {
	test();
	return 0;
}
