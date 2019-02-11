#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int val;
    Node(int v) : val(v), left(nullptr), right(nullptr){}
};
bool isValidSerialization(string preorder) {
    std::string::size_type pos;
    std::vector<std::string> result;
    std::string pattern = ",";
    std::string str = preorder + ",";
    int size = str.size();
    for(int i=0; i<size; i++) {
	pos = str.find(pattern, i);
	if(pos<size) {
	    std::string s = str.substr(i,pos-i);
	    result.push_back(s);
	    i = pos+pattern.size()-1;
	}
    }
    for (auto s : result) {
	if (s == "#" ) {

	}

    }

    return true;
}
int main( int argc, char *argv[] ) {
    std::string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    isValidSerialization(preorder);

    return 0;
}
