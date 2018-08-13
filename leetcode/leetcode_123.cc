#include <vector>
#include <iostream>
using namespace std;
struct Profit{
    int s;
    int e;
    int p;
};
int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1){
	return 0;
    }
    int L[3] ={0, 0, 0}, G[3] = {0, 0, 0};
    for (int i = 1; i < prices.size(); ++i){
	int diff = prices[i] - prices[i-1];
	for (int j = 2; j >= 1; --j){
	    L[j] = max(G[j-1] + max(diff, 0), L[j] + diff);
	    G[j] = max(G[j], L[j]);
	}
    }
    return G[2];
}


int main( ) {
    /*
    vector<int> vs = {1,5,2, 7, 3, 9};
    cout << maxProfit(vs) << endl;
    vector<int> vs = {7,6,4,3,1};
    cout << maxProfit(vs) << endl;
    */
    vector<int> vs = {8,6,4,3,3,2,3,5,8,3,8,2,6};
    cout << maxProfit(vs) << endl;
    return 0;
}
