#include <string>
#include <stack>
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class BSTIterator {
    stack<TreeNode *> mins;
public:
    BSTIterator(TreeNode *root) {
        
	while ( root != nullptr) {
		mins.push(root);
		root = root->left;
	}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
	return !mins.empty();
        
    }

    /** @return the next smallest number */
    int next() {
       auto top = mins.top(); 
       int result = top->val;
	mins.pop();
       auto right = top->right;
       while (right != nullptr) {
	    mins.push(right);
	    right = right->left;
       }
    }
};

int main() {
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
