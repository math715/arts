/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 */

// @lc code=start
class Solution {
public:
    string originalDigits(string s) {
        int w[26] = {0}; 
        for (auto c : s) {
            w[c - 'a']++;
        }
        
        auto get_string = [&](const std::string &str, const char c,
                            const char nc) -> std::string {
            int n = w[c - 'a'];
            std::string ans;
            if (n > 0) {
                ans = string(n, nc);
                for (auto cc : str) {
                w[cc - 'a'] -= n;
                }
            }
            return ans;
        };
        std::string zero = get_string("zero", 'z', '0');
        std::string two = get_string("two", 'w', '2');
        std::string four = get_string("four", 'u', '4');
        std::string three = get_string("three", 'r', '3');
        std::string six = get_string("six", 'x', '6');
        std::string seven = get_string("seven", 's', '7');
        std::string five = get_string("five", 'v', '5');
        std::string eight = get_string("eight", 'g', '8');
        std::string nine = get_string("nine", 'i', '9');
        std::string one = get_string("one", 'o', '1');
        std::string ans;
        ans += zero + one + two + three + four;
        ans += five + six + seven + eight + nine;
        return ans;

    }
};
// @lc code=end

