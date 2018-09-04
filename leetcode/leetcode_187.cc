#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
	 map<string, int> dna_map;
	 vector<string> result;
	 if (s.size() < 10) {
	     return result;
	 }
	 for (int i = 0; i < s.size() - 9 ; ++i) {
	     string t = s.substr(i, 10);
	     if (dna_map.find(t) != dna_map.end() ){
		 dna_map[t]++;
	     } else {
		 dna_map[t] = 1;
	     }
	 }
	 for (auto &it : dna_map) {
	     if (it.second > 1){
		 result.push_back(it.first);
	     }
	 }
	 return result;
}

int main() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto vs = findRepeatedDnaSequences(s);
    for (auto v : vs ){
	cout << v << endl;
    }
    return 0;
}
