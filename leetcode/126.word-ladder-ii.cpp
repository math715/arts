/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
public:
    vector<int> transform(string &s, unordered_map<string, int> &t){
        vector<int> res;
        for (int i = 0; i < s.length(); ++i) {
                string w = s;
                for (char c = 'a'; c <= 'z'; ++c){
                        if (s[i] == c) {
                                continue;
                        }
                        w[i] = c;
                        auto it = t.find(w);
                        if (it != t.end()){
                                res.push_back(it->second);
                        }
                }
        }
        return res;
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        wordList.push_back(beginWord);
        map<int, std::vector<int>> tables;
        unordered_map<string, int> ss;
        for (int i = 0; i < wordList.size(); ++i) {
                ss[wordList[i]] = i;
        }
         for (int i = 0;i < wordList.size(); ++i) {
                auto vs = transform(wordList[i], ss);
                for (auto v : vs) {
                        tables[i].push_back(v);
                }
        }
        queue<pair<int, vector<string>>> que;
        vector<string> words;
        words.push_back(beginWord);
        int n = wordList.size();
        vector<bool> flags(n, false);
        flags[n-1] = true;
        que.push(make_pair(n-1, words));
        while (!que.empty()){
                int w = que.size();
                vector<int> visit;
                while (w--) {
                        auto start = que.front().first;
                        words = que.front().second;
                        que.pop();
                        if (wordList[start] == endWord) {
                                result.push_back(words);
                                continue;
                        }
                        for (int i = 0; i < tables[start].size(); ++i) {
                                int v = tables[start][i];
                                if (flags[v]) {
                                        continue;
                                }
                                visit.push_back(v);
                                vector<string> tmp = words;
                                tmp.push_back(wordList[v]);
                                que.push(make_pair(v, tmp));
                        }

                }
                if (result.size()){
                        break;
                }
                for (auto v : visit) {
                        flags[v] = true;
                }
        }
        return result;
    }
};
// @lc code=end

