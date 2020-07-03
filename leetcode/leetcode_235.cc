#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	if (p->val > q->val) {
		std::swap(p->val, q->val);
	}
	TreeNode *r = root;
	while(!(r->val == p->val || r->val == q->val || (r->val > p->val && r->val < q->val))){
		if (p->val < r->val && q->val < r->val) {
			r = r->left;
		} else if (p->val > r->val && q->val > r->val) {
			r = r->right;
		}
	}
	return r;
}

int main( int argc, char *argv[]) {
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	TreeNode *p = new TreeNode(2);
	TreeNode *q = new TreeNode(1);
	auto res = lowestCommonAncestor(root, p, q);
	std::cerr << res->val << std::endl;

}
