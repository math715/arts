#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <climits>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
	string result;
	if (numerator == 0 || denominator == 0) {
		return "0";
	}
	int sign = 1;
	long int n = numerator; 
	long int d = denominator;
	if ((n < 0) ^ ( d < 0)) {
		sign = -1;
	}
        n = n > 0 ? n : -n;
        d = d > 0? d : -d;
	long  rem ;
	if (n % d == 0){
		result = to_string(n/d);
		return sign == 1 ? result : '-' + result;;
	} else {
		rem = n % d;
		result = to_string(n/d) + '.';
	}
	map<long long int, int> m;
	int index = result.size();
	while ( rem > 0 && m.find(rem) == m.end()){
		m[rem] = index;
		rem *= 10;
		result += to_string(rem/d);
		rem = rem % d;
		index++;
	}
	if (rem != 0 ){
		result.insert(m[rem], 1, '(');
		result.push_back(')');
	}
	return sign == 1 ? result : '-' + result;

}
    string fractionToDecimal2(int numerator, int denominator) {
        long long l_numerator = numerator;
        long long l_denominator = denominator;
        long long rest = 0;

        string result = "";
        unordered_map<long long , int> u_map;
        bool is_positive = true;
        if (l_denominator == 0) return result;
        if (l_numerator == 0) return "0";
        if (l_numerator == INT_MIN && l_denominator == -1) return "2147483648";
        if (l_numerator < 0) {
            is_positive = 1 - is_positive;
            l_numerator = - l_numerator;
        }
        if (l_denominator < 0) {
            is_positive = 1 - is_positive;
            l_denominator = - l_denominator;
        }
        if (l_numerator % l_denominator == 0) {
            result = to_string(l_numerator/l_denominator);
        } else {
            result = to_string(l_numerator / l_denominator) + '.';
        }

        rest = l_numerator % l_denominator;
        int index = result.length(); // starting point
        while (rest != 0 && u_map.find(rest) == u_map.end()) {
            u_map[rest] = index;
            rest *= 10;
            result += to_string(rest / l_denominator);
            rest = rest % l_denominator;
            index++;
        }
        if (rest != 0) {
            result.insert(u_map[rest], 1, '(');
            result.insert(result.length(), 1, ')');
        }
        if (is_positive)
            return result;
        else
            return "-" + result;
    }

int main( ) {
	cout << fractionToDecimal(-2147483648, 1 ) << endl;
	return 0;
}
