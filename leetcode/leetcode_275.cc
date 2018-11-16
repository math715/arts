#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
int hIndex(vector<int>& citations) {
    if (citations.empty()){
	return 0;
    }
    int n = citations.size() -1;
    int hIndex = 0;
    int l = 0;
    int r = n ;
    while (l <= r) {
	int mid = (l + r) >> 1;
	int num = n + 1 - mid;
	if (citations[mid] >= num){
	    r = mid - 1;
	    hIndex = num;
	} else {
	    l = mid + 1;
	}
    }
    return hIndex;
}

int main( int argc, char *argv[] ) {
    // vector<int> citations = {0, 1};
    vector<int> citations = {0,1,3,5,6};
    cout << hIndex(citations) << endl;

    return 0;
}
