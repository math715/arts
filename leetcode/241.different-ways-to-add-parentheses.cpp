 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); ++i) {
                char op = input[i];
                if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                        auto left = diffWaysToCompute(input.substr(0, i));
                        auto right = diffWaysToCompute(input.substr(i+1));
                        for (auto l : left) {
                                for (auto r : right) {
                                        if (op == '+') {
                                                res.push_back(l + r);
                                        } else if (op == '-') {
                                                res.push_back(l - r);
                                        } else {
                                                res.push_back(l * r);
                                        }
                                }
                        }
                }
        }
        if (res.empty()) {
                int value = stoi(input);
                res.push_back(value);
                return res;
        }
        return res;

    }
};
// @lc code=end

