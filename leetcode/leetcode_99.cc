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
	vals.push_back(root);
	if (root->right){
		inOrderTraversal(root->right, vals);
	}
}

void recoverTree(TreeNode* root) {
	if (root == nullptr){
		return ;
	}
	if ( root->left == nullptr && root->right == nullptr){
		return;
	}
	vector<TreeNode *> values;
	inOrderTraversal(root, values);
	//first
	int a;
	for (int i = 0; i < values.size() - 1; ++i){
		if (values[i]->val > values[i+1].val){
			a = i;
			break;
		}
	}
	int b = a;
	for (int i = a + 1; i < values.size() - 1; ++i){
		if (values[i]->val < values[i+1].val){
			b = i + 1;
			break;
		}
	}
	swap(values[a].val, values[b].val)
}

int main() {
}
