#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool isInterleave(string s1, string s2, string s3) {
	vector<vector<int>> dp;
	int m = s1.size();
	int n = s2.size();
	if ( m + n != s3.size()){
		return false;
	}
	dp.resize(m + 1);
	for (int i = 0; i <= m; ++i){
		dp[i].resize(n+1, 0);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= m ; ++i){
		dp[i][0] = dp[i-1][0] == 1 ?  s3[i-1] == s1[i-1] : 0;
	}
	for (int i = 1; i <= n; ++i){
		dp[0][i] = dp[0][i-1] == 1 ?  s3[i-1] == s2[i-1] : 0;
	}
	for (int i = 1; i <= m; ++i){
		for (int j = 1; j <= n; ++j){
			if ( (dp[i-1][j] == 1 && s3[i+j-1] == s1[i-1] )|| 
				(dp[i][j-1] == 1 && s3[i+j-1] == s2[j-1])) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = 0;
			}	
		}
	}
	return dp[m][n];

}

int main() {
	string s1, s2,s3;
	s1 = "aabcc";
	s2 = "dbbca";
	s3 = "aadbbcbcac";
	cout << isInterleave(s1, s2, s3) << endl;
	s3 = "aadbbbaccc";
	cout << isInterleave(s1, s2, s3) << endl;
	s1 = "";
	s2 = "";
	s3 = "a";
	cout << isInterleave(s1,s2, s3) << endl;

	return 0;
}
