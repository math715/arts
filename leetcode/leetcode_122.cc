#include <vector>
#include <iostream>

using namespace std;
int maxProfit(vector<int>& prices) {
	int max_profit = 0;
	if (prices.size() == 0 || prices.size() == 1){
		return max_profit;
	}
	int small = prices[0];
	int tmp_profit = 0;
	for (int i = 1; i < prices.size(); ++i){
		if (prices[i] > small){
			if (prices[i] - small > tmp_profit){
				tmp_profit = prices[i] - small;
			} else {
				max_profit += tmp_profit;
				small = prices[i];
				tmp_profit = 0;
			}
		} else {
			max_profit += tmp_profit;
			tmp_profit = 0;

			small = prices[i];
		}
	}
	max_profit += tmp_profit;
	return max_profit;
}

int main() {
	/*
	   vector<int> prices = {7,1,5,3,6,4};
	   cout << maxProfit(prices) << endl;
	   vector<int> prices = {1, 2,3, 4, 5};
	   cout << maxProfit(prices) << endl;
	   vector<int> prices = {1, 5, 4, 2, 7};
	   cout << maxProfit(prices) << endl;
	   */
	vector<int> prices = {2, 1, 2, 0, 1};
	cout << maxProfit(prices) << endl;

	return 0;
}
