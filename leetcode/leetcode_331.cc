#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;


bool isValidSerialization(string preorder) {
    int n = preorder.size();
    if (n == 0) {
	return true;
    }
    vector<string> vs;
    int pos = -1;
    for(int i = 0; i < n; i++) {
	if(preorder[i] == ',') {
	    vs.push_back(preorder.substr(pos+1, i-pos-1));
	    pos = i;
	}
    }
    if(preorder[n-1] != '#') return false;

    vs.push_back("#");
    int cnt = 1;
    for(int i = 0; i < vs.size(); i++) {
	if(cnt <= 0) return false;
	if(vs[i] == "#") cnt -= 1;
	else cnt += 1;
    }
    return cnt == 0;




}

int main( int argc, char *argv[] ) {

    return 0;
}
