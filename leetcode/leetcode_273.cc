#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
string Thousand( map<int, string> &nm, int n ){
    string result;
    if ( n >= 100 ) {
	int m = n / 100;
	result += nm[m] + " Hundred ";
	n = n % 100;
    }
    if ( n >= 20) {
	int a = n / 10 * 10;
	if (n%10 != 0) {
	    result += nm[a] + " " + nm[n%10] + " ";
	} else {
	    result += nm[a] + " ";
	}
    } else {
	if (n != 0) {
	    result += nm[n] + " ";
	}
    }
   return result;
}
string numberToWords(int num) {
    if (num == 0 ) {
	return "Zero";
    }
    map<int, string> nm = {
	{0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
	{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
	{18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"},
	{80, "Eighty"}, {90, "Ninety"}, {100, "Hundred"},
    };
    int idx = 0;
    int n = num;
    string result ;
    if (n / 1000000000 > 0) {
	int t = n / 1000000000;
	result += nm[t] + " Billion ";
	n = n % 1000000000;
    } 
    if (n / 1000000 > 0 ) {
	result += Thousand(nm, n / 1000000);
	result += "Million " ;
	n = n % 1000000;
    }
    if (n / 1000 > 0) {
	result += Thousand(nm, n / 1000);
	result += "Thousand ";
	n = n % 1000;
    }
    if ( n > 0 ){
	result += Thousand(nm, n);
    }
    result = result.substr(0,result.length()-1);
    return result;
}


int main( int argc, char *argv[] ) {
    cout << numberToWords(0) << endl;
    cout << numberToWords(100) << endl;
    cout << numberToWords(123) << endl;
    cout << numberToWords(12345) << endl;
    cout << numberToWords(1234567) << endl;
    cout << numberToWords(1234567891) << endl;
    if ("One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One" == numberToWords(1234567891)) {
	cout << "ok" << endl;
    } else {
	cout << "error" << endl;
    }


    return 0;
}
