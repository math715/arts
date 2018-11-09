#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Traversal(TreeNode *root, vector<int> &ves, int k) {
    if (root == nullptr) {
	return;
    }
    Traversal(root->left, ves, k);
    ves.push_back(root->val);
    Traversal(root->right, ves, k);
}
int kthSmallest(TreeNode* root, int k) {
    vector<int> ves;
    Traversal(root, ves, k);
    return ves[k-1];
}

int main( int argc, char *argv[] ) {
    TreeNode *t = new TreeNode(5);
    t->left = new TreeNode(3);
    t->right = new TreeNode(6);
    t->left->left = new TreeNode(2);
    t->left->right = new TreeNode(4);
    t->left->left->left = new TreeNode(1);
    cout << kthSmallest(t, 3) << endl;;
    

    return 0;
}
