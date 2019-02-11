#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    if (prices.size()<= 1) {
	return 0;
    }
    int n = prices.size();
    vector<int> buy, sell, cooldown;
    buy.resize(n + 1, 0);
    sell.resize(n + 1, 0);
    cooldown.resize(n + 1, 0);
    buy[0] = INT32_MIN;
    for (int i = 1; i < n + 1; ++i){
	buy[i] = max(buy[i-1], cooldown[i-1] - prices[i-1]);
	sell[i] = max(sell[i-1], buy[i-1] + prices[i-1]);
	cooldown[i] = max(sell[i-1], max(buy[i-1], cooldown[i-1]));

    }
    return max(buy[n], max(sell[n], cooldown[n]));

}
namespace solution2{
int maxProfit(vector<int>& prices) {
    if (prices.size()<= 1) {
	return 0;
    }
    int n = prices.size();
    vector<int> buy, sell, cooldown;
    buy.resize(n + 1, 0);
    sell.resize(n + 1, 0);
    cooldown.resize(n + 1, 0);
     
    sell[0] = -prices[0];
    for (int i = 1; i <  prices.size(); ++i){
	buy[i] = max(buy[i-1], cooldown[i-1]);
	sell[i] = max(sell[i-1], buy[i-1] - prices[i]);
	cooldown[i] = sell[i-1] + prices[i];

    }
    return max(buy[n-1], max(sell[n-1], cooldown[n-1]));

}
}

int main( int argc, char *argv[] ) {
    vector<int> prices = {1,2,3,0,2};
    // vector<int> prices = {1,2};
    cout << maxProfit(prices) << endl;
    cout << solution2::maxProfit(prices) << endl;

    return 0;
}
