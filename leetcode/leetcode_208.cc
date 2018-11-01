#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;
class Trie {
    public:
	/** Initialize your data structure here. */
	Trie() {

	}
    

	/** Inserts a word into the trie. */
	void insert(string word) {
	    dicts.insert(word);
	    for (int i = 0; i < word.size(); ++i) {
		cout << word.substr(0, i+1) << endl;
		prefixs.insert(word.substr(0, i+1));
	    }


	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
	    return dicts.find(word) != dicts.end();

	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
	    return prefixs.find(prefix) != prefixs.end();


	}
	unordered_set<string> dicts;
	unordered_set<string> prefixs;
	
};

int main( int argc, char *argv[] ) {
    Trie trie;
    /*
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // returns true
    cout << trie.search("app")  << endl;     // returns false
    cout << trie.startsWith("app") << endl; // returns true

    trie.insert("app");   
    cout << trie.search("app") << endl;     // returns true
    */
    trie.insert("a");
    cout << trie.search("a") << endl;

    cout << trie.startsWith("a") << endl;;


    return 0;
}
