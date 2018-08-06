#include <string>
#include <vector>
#include <iostream>
using namespace std;

string outputFixWidth(vector<string>& words, int words_len, int maxWidth) {
	string result;
	if (words.size() > 1){
		int space_cnt = words.size() - 1;
		int space_cnt_per = (maxWidth - words_len) / space_cnt;
		int space_rem = maxWidth - words_len - space_cnt * space_cnt_per;
		for (int i = 0; i < words.size() - 1; ++i){
			result.append(words[i]);
			result.append(space_cnt_per, ' ');
			if (space_rem > 0){
				result.append(1 ,' ');
				space_rem--;
			}
		}
		result.append(words[words.size() - 1]);
	} else {
		result.append(words[0]);
		result.append(maxWidth - words[0].size(), ' ');
	}
	return result;
}

string lastline(vector<string> &words, int maxWidth){
	string result;
	int cnt = 0;
	result.append(words[0]);
	cnt += words[0].size();
	for (int i = 1; i < words.size(); ++i){
		result.append(1, ' ');
		result.append(words[i]);
		cnt += words[i].size() + 1;
	}
	result.append(maxWidth - cnt, ' ');
	return result;
}
vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> result;
	vector<string> temp;
	int line_length = 0;
	int line_word_num = 0;
	int cnt = 0;
	for ( int i = 0; i < words.size(); ++i ){
		if (line_length + line_word_num + words[i].size() > maxWidth){
			auto res = outputFixWidth(temp, line_length, maxWidth);
			result.push_back(res);
			temp.clear();
			temp.push_back(words[i]);
			line_word_num  = 1;
			line_length = words[i].size();
		} else {
			temp.push_back(words[i]);
			line_length += words[i].size();
			line_word_num++;
		}
	}
	auto res = lastline(temp, maxWidth);
	result.push_back(res);
	return result;
}



int main() {
	// vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
	// vector<string> words = {"What","must","be","acknowledgment","shall","be"};
	vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"};
	auto result = fullJustify(words, 20);
	for (auto r : result) {
		cout << r << endl;
	}
	return 0;
}
