#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
/*
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 */
struct Trie {
    char c;
    bool end;
    Trie *nodes[26];
    Trie() {
	
	end = false;
	for (int i = 0; i < 26; ++i) {
	    nodes[i] = nullptr;
	}
    }
};
class WordDictionary {
    public:
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
	    words_.insert(word);
	    Trie *t = &trie;
	    for (int i = 0; i < word.size(); ++i ) {
		int c = word[i] - 'a';
		if (t->nodes[c] == nullptr){
		    t->nodes[c] = new Trie();
		}
		t = t->nodes[c];
	    }
	    t->end=true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
	    bool flag = true;
	    for (auto w : word) {
		if (w == '.'){
		    flag = false;
		    break;
		}
	    }
	    if (flag) {
		return words_.find(word) != words_.end();
	    } else {
		return dfs(0, word, &trie);
	    }
	}
	bool dfs(int idx, const string word, Trie *t){
	    if (word.empty()&&t->end){
		return true;
	    }
	    if (idx == word.size() ) {
		return t->end;
	    }

	    if (word[idx] == '.' ){
		for (int i = 0; i < 26; ++i) {
		    if (t->nodes[i] != nullptr && dfs(idx+1,word, t->nodes[i])) {
			return true;
		    }
		}
		return false;
	    } else {
		int c = word[idx] - 'a';
		if (t->nodes[c] != nullptr) {
		    return dfs(idx+1, word, t->nodes[c]);
		} else {
		    return false;
		}
	    }
	}
	set<string> words_;
	Trie trie;
};

int main( int argc, char *argv[] ) {
    WordDictionary dict;
    dict.addWord("at");
    dict.addWord("and");
    dict.addWord("an");
    dict.addWord("add");
    cout << dict.search("a") << endl;;
    cout << dict.search(".at") << endl;;
    dict.addWord("bat");
    cout << dict.search(".at") << endl;;
    cout << dict.search("an.") << endl;;
    cout << dict.search("a.d.") << endl;;
    cout << dict.search("b.") << endl;;
    cout << dict.search("a.d") << endl;;
    cout << dict.search(".") << endl;;
    cout << dict.search("pad") << endl;
    cout << dict.search("bad") << endl;
    cout << dict.search(".ad") << endl;
    cout << dict.search("..d") << endl;

    return 0;
}
