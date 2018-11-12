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
void dfs(TreeNode *p , set<string> &res, vector<int> vs) {
    if ( p == nullptr) {
	return ;
    }
    if (p != nullptr && p->right == nullptr && p->left == nullptr) {
	vs.push_back(p->val);
	string t = to_string(vs[0]);
	for (int i = 1; i < vs.size(); ++i){
	    t += "->" + to_string(vs[i]);
	}
	res.insert(t);
	return ;
    }
    vs.push_back(p->val);
    dfs(p->left, res, vs);
    dfs(p->right, res, vs);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    vector<int> temp;
    set<string> res;
    dfs(root, res, temp);
    for (auto r : res) {
	result.push_back(r);
    }
    return result;
}


int main( int argc, char *argv[] ) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->left = new TreeNode(15);
    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(18);
    auto vs =  binaryTreePaths(root) ;
    for (auto v : vs ) {
	cout << v << endl;
    }


    return 0;
}
