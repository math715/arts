#include <string> 
#include <iostream>

bool bf_find(const std::string &src, const std::string &dst) {
	bool result = false;
	for (int i = 0; i <= src.size() - dst.size(); ++i) {
		bool f = true;
		for (int j = 0; j < dst.size(); ++j) {
			if (src[i+j] != dst[j]) {
				f = false;
				break;
			}
		}
		if (f) {
			return true;
		}
	}
	return result;
}

int main() {
	std::string src = "hello";
	std::string dst = "hell";
	std::cout << bf_find(src, dst) << std::endl;
	dst = "holl";
	std::cout << bf_find(src, dst) << std::endl;
	return 0;
}
