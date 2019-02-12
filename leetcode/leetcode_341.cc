#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class NestedInteger {
    public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

void put(NestedInteger& list, vector<int> &vs) {
    if (list.isInteger()) {
	vs.push_back(list.getInteger());
    } else {
	for (auto l : list.getList()) {
	    put(l, vs);
	}
    }

}

class NestedIterator {
    public:
	NestedIterator(vector<NestedInteger> &nestedList) {
	    for (auto l : nestedList ) {
		put(l, vs);
	    }
	    it = vs.begin();
	}

	int next() {
	    int a = *it;
	    it++;
	    return a;

	}

	bool hasNext() {
	    return it != vs.end();

	}
    private:
	vector<int> vs;
	vector<int>::iterator it;

};

int main( int argc, char *argv[] ) {

    return 0;
}
