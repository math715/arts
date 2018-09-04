#include <iostream>
#include <cstdint>
using namespace std;
    int hammingWeight(uint32_t n) {
	int result = 0;
	while (n){
	    if (n & 1) {
		result++;
	    }
	    n >>= 1;
	}
	        
	return result;
	    }

int main() {
    cout << hammingWeight(128) << endl;
    return 0;
}
