#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    long a = A >= E ? A : E;
    long b = B >= F ? B : F;
    long c = C >= G ? G : C;
    long d = D >= H ? H : D;
    long m =(long) (C-A) *(D-B) + (G-E)*(H-F);
    if ( (c-a)>0 && (d-b)>0){
	m -= (c-a)*(d-b);
    }
    return m;
}

int main( int argc, char *argv[] ) {
    cout << computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1)<< endl;

    return 0;
}
