/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr  = 1;
        k -= 1;
        while (k > 0) {
            long step = Step(n, curr, curr + 1);
            if (k < step) {
                curr *= 10;
                k--;
            } else {
                k -= step;
                curr = curr + 1;
            }
        }
        return curr;
    }
    long Step(int n, long n1, long n2) {
        int ans = 0;
        while (n1 <= n) {
            ans += (min(static_cast<long>(n+1),n2)) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return ans;
    }
};
// @lc code=end

