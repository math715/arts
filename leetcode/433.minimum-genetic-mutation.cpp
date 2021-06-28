/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int N = bank.size();
        vector<bool> visited(N);
        queue<std::pair<std::string, int>> que;
        que.push({start, 0});

    
        while (!que.empty()) {
            auto kv = que.front();
            que.pop();
            if (kv.first == end) {
                return kv.second;
            }

            for (int i = 0; i < N; ++i) {
                if (!visited[i] && bank[i] != start) {
                    if (Distance(kv.first, bank[i]) == 1 ) {
                        que.push({bank[i], kv.second+ 1});
                        visited[i] = true;
                    }
                }
            }
        }
        return -1;

    }
    inline int  Distance(string &lhs, string &rhs) {
        int sum = 0;
        for (int i = 0; i < 8; ++i) {
            sum += lhs[i] == rhs[i]? 0 : 1;
        }
        return sum;
    }
};
// @lc code=end

