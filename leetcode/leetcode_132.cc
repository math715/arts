
#include <vector>
#include <string>
#include <iostream>
using namespace std;


bool isPalindrome(const string &str, int s, int e){
	while (s < e ){
		if (str[s] != str[e]){
			return false;
		}
		s++;
		e--;
	}
	return true;
}


int minCut(string s) {
	if (s.empty()){
		return 0;
	}
	int n = s.size();
	vector<int> dp;
	dp.resize(n, 0);
	for (int i = 1; i < n; ++i) {
		dp[i] = isPalindrome(s, 0, i)? 0 : i;
		for (int j = i ; j >= 1; --j){
			if (isPalindrome(s, j, i)){
			dp[i] = min(dp[i], dp[j-1] + 1);	
			}
		}
	}

	return dp[n-1];
}

int main() {
	string s = "aabaabc";
	cout << minCut(s)<< endl;
	return 0;
}

