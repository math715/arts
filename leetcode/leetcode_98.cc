#include <iostream>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inOrderTraversal(TreeNode *root, vector<int> &vals){
	if (root->left){
		inOrderTraversal(root->left, vals);
	}
	vals.push_back(root->val);
	if (root->right){
		inOrderTraversal(root->right, vals);
	}
}

bool isValidBST(TreeNode* root) {
	if (root == nullptr){
		return true;
	}
	if ( root->left == nullptr && root->right == nullptr){
		return true;
	}
	vector<int> values;
	inOrderTraversal(root, values);
	for (int i = 1; i < values.size(); ++i){
		if (values[i] <= values[i-1]) {
			return false;
		}
	}
	return true;
	
}

int main() {
}
