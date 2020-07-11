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
class RandomizedCollection {
	public:
		/** Initialize your data structure here. */
		RandomizedCollection() {

		}

		/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
		bool insert(int val) {
			bool res = true;
			if (table.find(val) != table.end()){
				res = false;
			}
			values.push_back(val);
			table[val].insert(values.size() -1);
			return res;
		}

		/** Removes a value from the collection. Returns true if the collection contained the specified element. */
		bool remove(int val) {
			bool res = false;
			auto it = table.find(val);
			if (it != table.end()){ 
				res = true;
				int idx = *table[val].begin();
				table[val].erase(idx);
				if (table[val].empty()){
					table.erase(val);
				}
				if (idx != values.size() - 1) {
					int v = values[values.size()-1];
					values[idx] = v;
					table[v].erase(values.size()-1);
					table[v].insert(idx);
				}
				values.pop_back();
			} 
			return res;
		}

		/** Get a random element from the collection. */
		int getRandom() {
			int n = values.size();
			int rnd = rand() % n;

			for (auto v : values) {
			cout << "v:" << v << " ";
}
			cout << endl;
			return values[rnd];
		}
	private:
		unordered_map<int, unordered_set<int>> table;
		vector<int> values;
};

void test() {
	RandomizedCollection* obj = new RandomizedCollection();
	bool param_1;
	param_1 = obj->insert(-1);
	cout << param_1 << " ";
	param_1 = obj->remove(-2);
	cout << param_1 << " ";
	param_1 = obj->insert(-2);
	cout << param_1 << " ";
	int param_3 = obj->getRandom();
	cout << param_3 << " ";
	param_1 = obj->remove(-1);
	cout << param_1 << " ";
	param_1 = obj->insert(-2);
	cout << param_1 << " ";
	param_3 = obj->getRandom();
	cout << param_3 << " ";
	cout << endl;
}

int main (int argc, char **argv) {
	test();
	return 0;
}
