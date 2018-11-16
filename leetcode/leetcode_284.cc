#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    private:
	bool cache;
	int data;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    cache = false;
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    if (cache){
		return data;
	    } else {
		cache = true;
		return data = Iterator::next();
	    }
        
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (!cache) {
	      return = Iterator::next();
	    } else {
		cache = false;
		return data;
	    }

	    
	}

	bool hasNext() const {
	    if (cache) return true;
	    return Iterator::hasNext();
	}
};

int main( int argc, char *argv[] ) {

    return 0;
}
