#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
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
int pow2(int x) {
    if (x==1) {
	return 1;
    }
    return (1 << x) - 1;
}
int countNodes(TreeNode* root) {
    if (root == nullptr){
	return 0;
    }
    int left_depth = 0;
    int right_depth = 0;
    for (TreeNode *r = root; r != nullptr; r = r->left){
	left_depth++;
    }
    for (TreeNode *r = root; r != nullptr; r = r->right){
	right_depth++;
    }
    if (left_depth == right_depth) {
	return pow2(left_depth);
    } else {
	return 1 + countNodes(root->left) + countNodes(root->right);
    }

}

int main( int argc, char *argv[] ) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(5);

    cout << countNodes(root) << endl;


    return 0;
}
