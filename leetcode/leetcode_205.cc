#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) {
	return false;
    }
    map<char, char> m1, m2;
    for (int i = 0; i < s.size(); ++i){
	char sc = s[i];
	char tc = t[i];
	if (m1.find(sc) == m1.end() && m2.find(tc) == m2.end() ) {
	    m1[sc] = tc; //insert
	    m2[tc] = sc;
	} else if (m1.find(sc) != m1.end() and m2.find(tc) != m2.end()){
	    if (sc != m2[tc] || tc != m1[sc]){
		return false;
	    }
	} else {
	    return false;
	}
    }
    return true;
}

int main( int argc, char *argv[] ) {
    cout << isIsomorphic("ab", "aa" ) << endl;

    return 0;
}
