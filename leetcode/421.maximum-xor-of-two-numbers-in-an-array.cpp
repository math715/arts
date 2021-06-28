/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
struct Tree {
    Tree() :one(nullptr), zero(nullptr){}
    Tree *one ;
    Tree *zero;
    int value;
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Tree *root = new Tree();
        for (int num : nums){
            Tree *now = root;
            for (int i = 31; i >= 0; --i) {
                int cur = ((num >> i) & 1);
                if (cur == 0 ) {
                    if (now->zero == nullptr) {
                        Tree *newT = new Tree();
                        now->zero = newT;                        
                    }
                    now = now->zero;
                } else {
                    if (now->one == nullptr) {
                        Tree *newT = new Tree();
                        now->one = newT;                        
                    }
                    now = now->one;
                }
            }
            now->value = num;
        }
        int ans = 0;
        for (int num : nums) {
            Tree *now = root;
            for (int i = 31; i >= 0; --i) {
                int cur = (num >>i) & 1;
                if (cur == 0) {
                    if (now->one) now = now->one;
                    else now = now->zero;
                } else {
                    if (now->zero) now = now->zero;
                    else now = now->one;
                }
            }
            ans = max(ans, num ^ (now->value));
        }
        return ans;        
    }
};
// @lc code=end

