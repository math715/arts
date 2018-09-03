#include <iostream>
using namespace std;

int trailingZeroes(int n) {
    int result = 0;
    while (n > 0){
	result += n / 5;
	n = n / 5;
    }
    return result;

}

int main() {
    cout << trailingZeroes(30) << endl;
    return 0;
}
