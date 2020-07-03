#include <vector>

#include <iostream>
#include <queue>

using namespace std;
int kthSmallest(vector<vector<int>> &matrix, int k) {
	std::priority_queue<int, vector<int>, less<int>> q;
	for (int i = 0; i < matrix.size(); ++i ){
		for (int j = 0; j < matrix[i].size(); ++j) {
			q.push(matrix[i][j]);
			if (q.size() > k) {
				q.pop();
			}
		}
	}
	return q.top();
}

int main() {
	vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
	std::cout << kthSmallest(matrix, 9) << std::endl;
	return 0;
}
