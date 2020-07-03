/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:


int Length(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(beginWord);
        queue<pair<string, int>> que;
        que.push(make_pair(beginWord, 1));
        wordList.erase(wordList.find(beginWord));
        while(!que.empty()){
            auto val = que.front();
            que.pop();
            if(val.first == endWord) return val.second;
            for(int i =0; i< val.first.size(); i++)  {
                string str = val.first;
                for(int j = 0; j < 26; j++)   {
                    str[i] = 'a'+j;
                    if(wordList.count(str) == 1) {
                        que.push(make_pair(str, val.second+1));
                        wordList.erase(str);
                    }
                }
            }
        }
        return 0;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> tables {wordList.begin(), wordList.end()};
    return Length(beginWord, endWord, tables);
}


};
// @lc code=end

