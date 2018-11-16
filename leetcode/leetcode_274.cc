#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end(), [](auto a, auto b) {
	    return a > b;
	    });
    int result = 0;
    for (int i = 0; i < citations.size(); ++i) {
	result = max(result, min(i+1, citations[i]));
    }
    return result;

}

int main( int argc, char *argv[] ) {
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << hIndex(citations) << endl;

    return 0;
}
