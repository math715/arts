#include <vector>
#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.empty()){
		return nullptr;
	}
	vector<int> small;
	vector<int> big;
	int mean = nums.size() / 2;
	for (int i = 0; i < mean; ++i){
		small.push_back(nums[i]);
	}
	TreeNode *root = new TreeNode(nums[i]);
	for (int i = mean+1; i< nums.size(); ++i){
		bgi.push_back(nums[i]);
	}
	root->left = sortedArrayToBST(small);
	root->right = sortedArrayToBST(big);
	return root;
}
