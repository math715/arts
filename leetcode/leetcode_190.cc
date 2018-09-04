#include <iostream>

using namespace std;

uint32_t reverseBits(uint32_t n) {
    int k = 32;
    uint32_t result = 0;
    while (k) {
	result = (result << 1) + (n & 1 );
	n >>= 1;
	--k;
    }
    return result;
	    
}


int main() {
    uint32_t n = 43261596;
    cout << reverseBits (n) << endl;
}
