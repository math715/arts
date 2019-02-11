#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> res, t;
    res.resize(n);
    for (int i = n - 1; i>=0; --i) {
	int d = distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));
	res[i] = d;
	t.insert(t.begin() + d, nums[i]);
    }
    return res;


}

int main( int argc, char *argv[] ) {

    return 0;
}
