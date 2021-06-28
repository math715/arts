/*
 * @lc app=leetcode id=420 lang=cpp
 *
 * [420] Strong Password Checker
 */

// @lc code=start
class Solution {
public:
    int strongPasswordChecker(string password) {

        int last_index=0;
        int a_flag = 0, A_flag = 0, i_flag = 0;
        int c[3] = {0, 0, 0};
        int nm = 0;
        for (int i = 0; i < password.size();) {
            auto ch = password[i];
            
            if (ch >= 'a' && ch <= 'z'){
                a_flag = 1;
            } else if (ch >= 'A'  && ch <= 'Z'){
                A_flag = 1;
            } else if (ch >= '0' && ch <= '9'){
                i_flag = 1;
            } else {
                
            }
            int length = 0;
            while (i < password.size() && ch==password[i]) {
                i++;
                length++;
            }
            if (length >= 3) {
                nm += length / 3;
                c[length % 3]++;
            } 
        }
        int n = password.size();
      int add = (A_flag ? 0 : 1) + (a_flag ? 0 : 1) + (i_flag ? 0 : 1);
        if (password.size() < 6) {
            return max(6 - n, add);
        }
        if (password.size() <= 20) {
            return max(add, nm);
        }
        int nd = password.size() - 20;
        if (nd <= c[0]){
            return max(nm - nd, add) + nd;
        }
        if (nd - c[0] <= 2 * c[1]){
            return max(nm - c[0] - (nd -c[0])/2, add) + nd;
        }
        if (nd - c[0] - 2*c[1] <= 3 * c[2]){
            return max(nm - c[0] - c[1]- (nd - c[0] - 2*c[1])/3, add) 
                      + nd;
        }
        return max(nm - c[0] - c[1] - c[2] - (nd - c[0] - 2*c[1] -3*c[2])/3, add) + nd;




        
    }
};
// @lc code=end

