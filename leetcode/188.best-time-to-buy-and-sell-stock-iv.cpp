/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        if (k > prices.size()) {
            int res = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] - prices[i-1] > 0) {
                    res += prices[i] - prices[i-1];
                }
            }
            return res;
        }
        int l[k+1];
        int g[k+1];
        memset(l, 0x00, sizeof(int) * (k + 1));
        memset(g, 0x00, sizeof(int) * (k + 1));

        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i-1];
            for (int j =  k ; j >= 1; --j) {
                l[j] =  max(g[j-1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
};
// @lc code=end

