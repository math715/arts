#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
enum STAT{
    START = 0,
    INTEGER = 1,
    DECIMAL = 2,
    EXPONENT = 3,
    END = 4,
};
bool isNumber(string s) {
    const char *p = s.c_str();
    STAT stat = START;
    bool result = false;
    bool symbol = false; // '+' or '-' flag;
    bool zero = false ; // integer '0' flag;
    bool non_zero = false;
    while (*p){
	if (stat == START){
	    if (isspace(*p)){
		p++;
	    } else {
		stat = INTEGER;
		result = true;
	    }
	} else if (stat == INTEGER) {
	    if (*p == '+' || *p == '-' ){
		if (symbol) { // multiple symbol '+' or '-'
		    result = false;
		    break;
		}
		symbol = true;
	    } else if (isdigit(*p)) {
		if (*p == '0' ){
		    if (zero) {
			result = false;
			break;
		    }
		    if (!non_zero) {
			zero = true;
		    }
		} else {
		    if (zero){
			result = false;
			break;
		    }
		    non_zero = true;
		}
	    } else if (*p == '.') {
		stat = DECIMAL;
	    } else if (*p == 'E' || *p == 'e'){
		stat = EXPONENT;
		symbol = false;
	    } else if (isspace(*p)) {
		stat = END;
	    } else {
		result = false;
	    }
	} else if (stat == DECIMAL) {
	    if (isdigit(*p)) {
		;
	    } else if (*p == 'E' || *p == 'e'){
		stat = EXPONENT;
		symbol = false;
	    } else {
		result = false;
		break;
	    }
	} else if (stat == EXPONENT) {
	    if ( *p == '+' || *p == '-'){
		if (symbol){
		    result = false;
		    break;
		}
		symbol = true;
	    } else if (isdigit(*p)){
		;
	    } else if (isspace(*p)){
		stat = END;
	    } else {
		result = false;
		break;
	    }

	} else if (stat == END) {
	    if (!isspace(*p)) {
		result = false;
		break;
	    }
	} else {
	    result = false;
	    break;
	}
	++p;
    }
    return result;

}

int main( int argc, char *argv[] ) {
    string test_str;
    test_str = "1";
    cout << "1 " << isNumber(test_str) << endl;
    test_str = "1.1";
    cout << "1 " << isNumber(test_str) << endl;
    test_str = "1.1E";
    cout << "0 " << isNumber(test_str) << endl;

    return 0;
}
