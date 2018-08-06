#include <string>
#include <iostream>
#include <vector>

using namespace std;


int minDistance(string word1, string word2) {
	int s = word1.size(); 
	int t = word2.size();
	vector<vector<int>> R;
	R.resize(t+1);
	for (int i = 0; i <= t; ++i) {
		R[i].resize(s + 1, 0);
	}
	for (int i = 0; i <= s; ++i){
		R[0][i] = i;
	}
	
	for (int i = 0; i <= t; ++i){
		R[i][0] = i;
	}

	for ( int i = 1; i <= t; ++i){
		for (int j = 1; j <= s; ++j){
			int t;
			if (word2[i-1] == word1[j-1]){
				t = R[i-1][j-1];
			} else {
				t = R[i-1][j-1] + 1;
			}
			t = R[i][j-1] + 1 > t ? t : R[i][j-1] + 1;
			t = R[i - 1][j] + 1 > t ? t : R[i-1][j] + 1;
			R[i][j] = t;
		}
	}
	return R[t][s];
}

int main( ) {
	string word1;
	string word2;
	word1 = "horse";
	word2 = "ros";
	cout << 3 << minDistance(word1, word2) << endl;

	word1 = "intention", word2 = "execution";
	cout << 5 << minDistance(word1, word2) << endl;
	return 0;
}
