#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void rightTree( TreeNode *root, int &depth, int cur_depth, vector<int> &result){
    if (root) {
	if (depth < cur_depth) {
	    depth += 1;
	    result.push_back(root->val);
	}
	if (root->right){
	    rightTree(root->right, depth, cur_depth+1, result);
	}
	if (root->left) {
	    rightTree(root->left, depth, cur_depth+1, result);
	}

    }
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
	return result;
    }
    int depth = 0;
    rightTree(root, depth, 1, result);
    return result;

}

int main( int argc, char *argv[] ) {
       TreeNode *root = new TreeNode(4);
       root->left = new TreeNode(3);
       root->left->left = new TreeNode(2);
       root->left->left->left = new TreeNode(1);
       root->right = new TreeNode(5);
       root->right->right = new TreeNode(6);
       /*
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    */
    auto vs = rightSideView(root); 
    for (auto v : vs ){
	cout << v << " ";
    }
    cout << endl;

    return 0;
}
