#include <string> 
#include <iostream>
#include <vector>


bool bf_find(const std::string &src, const std::string &dst) {
	long hash_value = 0;
	for (int i = 0; i < dst.size(); ++i){
		hash_value = dst[i] + hash_value * 33; 
	}
	int l = dst.size();
	std::vector<long> hash_tables;
	hash_tables.resize(l,1);
	for (int i = 1; i < l; ++i) {
		hash_tables[i] = hash_tables[i-1] * 33;
	}
	long sh = 0;
	for (int i = 0; i < dst.size(); ++i) {
		sh += src[i] * hash_tables[l-1-i];
	}
	if (sh == hash_value){
		return true;
	}
	for (int i = 1; i <= src.size() - dst.size(); ++i ) {
		sh = sh - src[i] * hash_tables[l-1] + src[l+i];
		if (sh == hash_value) {
			return true;
		}
	}
	return false;
}

int main() {
	std::string src = "hello";
	std::string dst = "hell";
	std::string test;
	std::cout << bf_find(src, dst) << std::endl;
	dst = "holl";
	std::cout << bf_find(src, dst) << std::endl;
	return 0;
}
