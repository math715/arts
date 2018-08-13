#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool check(string s){
    if (s.size() > 1 && s[0] == '0' ){
	return false;
    } 
    if (s.size() == 3){
	if (s > "255" ){
	    return false;
	}
    }
    return true;
}
void backtrace(string s,int index, vector<string> result, vector<string> &results) {
    if (index == s.size() || result.size() > 4){
	if ( result.size() == 4){
	    string res;
	    for (auto  &r : result){
		res += r + '.';
	    }
	    res.pop_back();
	    results.push_back(res);
	}
	return ;
    }
    string t;
    for (int idx = 0; idx < 3; ++idx){
	vector<string> temp_result = result;
	t += s[index+idx];
	if (check(t)){
	    temp_result.push_back(t);
	    backtrace(s, index + idx + 1, temp_result, results);
	}
    }
}
vector<string> restoreIpAddresses(string s) {
    vector<string> temp_result;
    vector<string> results;
    backtrace(s, 0, temp_result, results);
    return results;
}

int main( int argc, char *argv[] ) {
    string s;
    // s = "25525511135";
    s = "1111";
    auto result = restoreIpAddresses(s);
    for (auto res : result){
	cout << res << endl;
    }
    return 0;
}
