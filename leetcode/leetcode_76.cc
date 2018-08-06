#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    int head = 0;
    int tail = 0;
    int min_window_len = s.size() + 1;
    int min_window_start = 0;
    int min_window_end = 0;
    int cnt = 0;
    unordered_map<char, int> char_map;
    for (auto a : t){
	char_map[a]++;
    }
    unordered_map<char, int> temp_map = {char_map.begin(), char_map.end()};
    while(tail < s.size()) {
	if (temp_map.find(s[tail]) == temp_map.end()) {
	    tail++;
	    continue;
	} 
	temp_map[s[tail]]--;
	if (temp_map[s[tail]] >= 0){
	    cnt++;
	}
	while (cnt == t.size()) {
	    if (temp_map.find(s[head]) == temp_map.end()){
		head++;
		continue;
	    }
	    if (temp_map[s[head]] < 0){
		temp_map[s[head]]++;
		head++;
	    } else {
		int cur = tail - head + 1;
		// cout<< cnt << " " << s.substr(head, tail - head + 1) << endl;
		if (cur < min_window_len) {
		    min_window_len = cur;
		    min_window_start = head;
		    min_window_end= tail;
		     // cout<< min_window_len << "\t" << s.substr(min_window_start, min_window_len) << endl;
		}
		temp_map[s[head]]++;
		cnt--;
		head++;
		break;
	    }
	}
	tail++;
    }
    if (min_window_len > s.size()){
	return "";
    } else {
	return s.substr(min_window_start, min_window_len);
    }
}

int main() {
    string s;
    string t;
    s = "ADOBECODEBANC", t ="ABC";
    cout << minWindow(s, t) << endl;
    s = "a", t = "a";
    cout << minWindow(s, t) << endl;
    return 0;
}

