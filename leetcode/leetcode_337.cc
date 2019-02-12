#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int dfs(TreeNode *root) {
    if (root == nullptr) {
	return 0;
    }
    int a = root->val ;
    if (root->left) {
	a += dfs(root->left->left) +  dfs(root->left->right);
    }
    if (root->right) {
	a += dfs(root->right->left) + dfs(root->right->right);
    }
    int b = dfs(root->left) + dfs(root->right);
    return max(a, b);
    
}
int rob(TreeNode* root) {
    return dfs(root);
}

int main( int argc, char *argv[] ) {
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << rob(root) << endl;
    

    return 0;
}
