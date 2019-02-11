#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> array;
    array.resize(26, 0);
    for (int i = 0; i < s.size(); ++i) {
	array[s[i]-'a']++;
    }
    string result = " ";
    vector<bool> visited(26, false);
    for (int i = 0; i < s.size(); ++i) {
	char c = s[i] - 'a';
	array[c]--;
	if (visited[c]) {
	    continue;
	}
	while (c < result.back() && array[result.back()-'a']) {
	    visited[result.back()-'a'] = false;
	    result.pop_back();
	}
	result += s[i];
	visited[c] = true;
    }
    return result.substr(1);
}

int main( int argc, char *argv[] ) {
    cout << removeDuplicateLetters("bcabc") << endl;
    cout << removeDuplicateLetters("cbacdcbc") << endl;
    cout << removeDuplicateLetters("wmxkuuoordmnpnebikzzujdpscpedcrsjphcaykjsmobturjjxxpoxvvrynmapegvtlasmyuddgxygkaztmbpkrnukbxityz") << endl;

    return 0;
}
