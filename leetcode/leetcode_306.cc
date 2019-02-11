#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
string getSum(string num1, string num2) {
    int val, flag = 0, len1 = num1.size(), len2 = num2.size(); 
    string sum;
    while(len1 || len2)
    {
	int val = 0;
	if(len1 > 0) val += num1[len1 -1] - '0', len1--;
	if(len2 > 0) val += num2[len2 -1] - '0', len2--;
	sum += to_string((val+flag)%10);
	flag = (val+flag)/10;
    }
    if(flag) sum += "1";
    reverse(sum.begin(), sum.end());
    return sum;

}
bool dfs( string num1, string num2, string num3 ) {
    cout << num1 << "\t" << num2 << "\t" << num3 << endl;
    if (num3.size() == 0) {
	return true;
    }
    string sum_str = getSum(num1, num2);
    if (sum_str.size() <= num3.size()){
	for (int i = 0 ; i < sum_str.size(); ++i) {
	    if (sum_str[i] != num3[i]){
		return false;
	    }
	}
	string new_num3 = num3.substr(sum_str.size());
	if (new_num3.size() > 0 && new_num3[0] == '0'){
	    return false;
	}
	if (dfs(num2, sum_str, new_num3)) {
	    return true;
	} else {
	    return false;
	}
    } else {
	return false;
    }
}
bool isAdditiveNumber(string num) {
    string num1;
    string num2;
    string num3;
    if (num.size() < 2){
	return false;
    }
    for (int i = 1; i <= num.size()-2; ++i) {
	num1 = num.substr(0, i);
	for (int j = i+1; j <= num.size() - 1; ++j) {
	    num2 = num.substr(i, j-i);
	    num3 = num.substr(j);
	    if (dfs( num1, num2, num3)) {
		return true;
	    }
	    if (num[i] == '0') {
		break;
	    }
	}
	if (num[0] == '0') {
	    break;
	}
    }
    return false;
}
int main( int argc, char *argv[] ) {
    cout << isAdditiveNumber("11235") << std::endl;
    cout << isAdditiveNumber("199100199") << endl;
    cout << isAdditiveNumber("1123581") << std::endl;
    cout << isAdditiveNumber("1") << endl;
    cout << isAdditiveNumber("111122335588143") << endl;
    cout << isAdditiveNumber("123") << endl;


    return 0;
}
