#include <string>
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(vector<int> &result, TreeNode *root){
	if (root == nullptr){
		return ;
	}
	if (root->left){
		inorder(result, root->left);
	}
	result.push_back(root->val);
	if (root->right) {
		inorder(result, root->right);
	}
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	inorder(result, root);
	return result;
}

int main() {
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	auto result = inorderTraversal(root) ;
	for (auto v : result){
		cout << v << " ";
	}
	cout << endl;
	return 0;
}


