/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int m = 1;

        while (n >= m) {
            n -= m;
            m++;
        }
        return m - 1;
    }
};
// @lc code=end

