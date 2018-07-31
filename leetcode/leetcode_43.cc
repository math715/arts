/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Note:
    The length of both num1 and num2 is < 110.
    Both num1 and num2 contain only digits 0-9.
    Both num1 and num2 do not contain any leading zero, except the number 0 itself.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

#include <string> 
#include <iostream>
using namespace std;
string multiply(string num1, string num2) {
    string result;
    // string const number_str = "0123456789";
    if (num1 == "0" || num2 == "0"){
        return "0";
    }
    if (num2.size() > num1.size()){
        swap(num1, num2);
    }
    for (int i = 0; i < num2.size(); ++i) {
        string temp;
        int last = 0;
        for (int j = num1.size() - 1; j >= 0; --j) {
            int t = (num1[j] - '0') * (num2[i] - '0') + last;
            last = t / 10;
            char tempchar = t%10 + '0';
            temp = tempchar + temp;
        }
        if (last > 0) {
            char tempchar = (last + '0');
            temp = tempchar + temp;
        }
        if (!result.empty()){
            int last_char = 0;
            result += '0';
            int result_idx = result.size() - 1;
            for (int j = temp.size() - 1; j >= 0; --j){
                int value = (temp[j] - '0') + (result[result_idx] - '0') + last_char;
                last_char = value / 10;
                result[result_idx] = '0' + (char)(value%10);
                result_idx--;
            }
            while (last_char > 0) {
                if (result_idx >= 0){
                    int value =  result[result_idx] - '0' + last_char;
                    result[result_idx] = char (value%10) + '0';
                    last_char = value / 10;
                    result_idx--;
                } else {
                    result = '1' + result;
                    break;
                }
            }
        } else {
            result = temp;
        }
    }
    return result;
    
}

int main () {
    string num1 = "321";
    string num2 = "567";
    // cout << multiply(num1, num2) << endl;
    // num1 = "123";
    // num2 = "456";
    // cout << multiply(num1, num2) << endl;
    // num1 = "71";
    // num2 = "168899993";
    // cout << multiply(num1, num2) << endl;
    // num1 = "17849419788197";
    // num1 = "17";
    // num2 = "877968504004372811";
    // cout << multiply(num1, num2) << endl;
    // num1 = "9133";
    // num2 = "0";
    // cout << multiply(num1, num2) << endl;
    num1 = "140";
    num2 = "721";
    cout << multiply(num1, num2) << endl;

    return 0;
}