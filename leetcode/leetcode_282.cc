#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

void buildResults(vector<string> &result, long cur_num, long multi_num, int cur_pose,  string cur_result, string num, int target) {
	if (cur_pose == num.length()) {
		if (cur_num == target) {
			result.push_back(cur_result);
		}
	} else {
		for (int i = cur_pose; i < num.length(); ++i) {
			if (num[cur_pose] == '0' && i != cur_pose){
				break;
			}
			long value = stol(num.substr(cur_pose, i - cur_pose+1));
			long max_value = stol(num.substr(cur_pose));
			std::string tmp_result;
			if (cur_pose == 0) {
			        tmp_result = cur_result + to_string(value);
				buildResults(result, value, value, i + 1, tmp_result, num, target);
			} else {
				if (max_value + cur_num >= target){
			        	tmp_result = cur_result + "+" + to_string(value);
					buildResults(result, cur_num + value, value, i + 1, tmp_result, num, target);
				}
				if (cur_num - max_value <= target){
			        	tmp_result = cur_result + "-" + to_string(value);
					buildResults(result, cur_num - value, -value, i + 1, tmp_result, num, target);
				}
			        tmp_result = cur_result + "*" + to_string(value);
				buildResults(result, cur_num - multi_num + multi_num * value, value * multi_num, i + 1, tmp_result, num, target);

			}
		}
	}
}

vector<string> addOperators(string num, int target) {
	vector<string> result;
	buildResults(result, 0, 0, 0, "", num, target);
	return result;

}

void test(string num, int target) {
	auto vs = addOperators(num, target);
	std::cerr << "-------------------" << std::endl;
	for (auto v : vs) {
		std::cerr << v << std::endl;
	}
}
int main() {
	test("123", 6);
	test("232", 8);
	test("105", 5);
	test("2147483647", 2147483647);
	test("123456789", 45);
	return 0;
}
/*
["1+2+3+4+5+6+7+8+9","1+2+3*4+5+6*7-8-9","1+2*3+4*5*6+7-89","1+2*3*4+5*6+7-8-9","1+2*3*4*5+6+7-89","1*2+3+4+5*6+7+8-9","1*2+3+45+67-8*9","1*2*3+4+5+6+7+8+9","1+23+4+5+6+7+8-9"]
["1*2*3*4*5-6-78+9","1*2*3*4+5+6-7+8+9","1*2*3+4+5+6+7+8+9","1*2*3+4+5-6*7+8*9","1*2*3+4-5*6+7*8+9","1*2*3+4-5*6-7+8*9","1*2*3-4*5+6*7+8+9","1*2*3-4*5-6+7*8+9","1*2*3-4*5-6-7+8*9","1*2*3-45+67+8+9","1*2*34+56-7-8*9","1*2*34-5+6-7-8-9","1*2+3*4-56+78+9","1*2+3+4+5*6+7+8-9","1*2+3+4-5+6*7+8-9","1*2+3+4-5-6+7*8-9","1*2+3+45+67-8*9","1*2+3-45+6+7+8*9","1*2+34+5-6-7+8+9","1*2+34+56-7*8+9","1*2+34-5+6+7-8+9","1*2+34-56+7*8+9","1*2+34-56-7+8*9","1*2-3*4+5+67-8-9","1*2-3+4-5-6*7+89","1*2-3-4*5+67+8-9","1*2-3-4+56-7-8+9","1*2-34+5*6+7*8-9","1*23+4*5-6+7-8+9","1*23-4-56-7+89","1+2*3*4*5+6+7-89","1+2*3*4+5*6+7-8-9","1+2*3*4-5+6*7-8-9","1+2*3+4*5*6+7-89","1+2*3+4*5-6+7+8+9","1+2*3-4-5-6*7+89","1+2*34-5*6+7+8-9","1+2+3*4*5+6-7-8-9","1+2+3*4+5+6*7-8-9","1+2+3*45-6-78-9","1+2+3+4+5+6+7+8+9","1+2+3+4+5-6*7+8*9","1+2+3+4-5*6+7*8+9","1+2+3+4-5*6-7+8*9","1+2+3-4*5+6*7+8+9","1+2+3-4*5-6+7*8+9","1+2+3-4*5-6-7+8*9","1+2+3-45+67+8+9","1+2-3*4*5+6+7+89","1+2-3*4+5*6+7+8+9","1+2-3*4-5+6*7+8+9","1+2-3*4-5-6+7*8...
*/
