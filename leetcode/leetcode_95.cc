#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees( vector<int> set){
    vector<TreeNode *> result;
    if (set.empty()){
	result.push_back(NULL);
	return result;
    }
    for (int i = 0; i < set.size(); ++i){
	vector<int> small_set;
	vector<int> big_set;
	int root_val = set[i];
	for (int j = 0; j < i; ++j){
	    small_set.push_back(set[j]);
	}
	for (int j = i + 1; j < set.size(); ++j){
	    big_set.push_back(set[j]);
	}
	vector<TreeNode *> left = generateTrees(small_set);
	vector<TreeNode *> right = generateTrees(big_set);
	for (int i = 0; i < left.size(); ++i){
	    for (int j = 0; j < right.size(); ++j){
		TreeNode *root = new TreeNode(root_val);
		root->left = left[i];
		root->right = right[j];
		result.push_back(root);
	    }
	}
    }
    return result;

}

vector<TreeNode*> generateTrees(int n) {
    vector<int> tree_set;
    for ( int i = 1; i <= n; ++i){
	tree_set.push_back(i);
    }
    vector<TreeNode*> result = generateTrees(tree_set);
    return result;
}

void printBST(TreeNode *root){
    queue<TreeNode *> tree_queue;
    tree_queue.push(root);
    while (!tree_queue.empty()){
	auto r = tree_queue.front();
	tree_queue.pop();
	if (r != nullptr){
	    cout << r->val << " ";
	} else {
	    cout << "null ";
	    continue;
	}
	if (r->left || r->right ){
	    tree_queue.push(r->left);
	    if (r->right != nullptr){
		tree_queue.push(r->right);
	    } else if (r->left != nullptr && (r->left->left != nullptr || r->left->right != nullptr)){
		tree_queue.push(r->right);
	    }
	}
    }
    cout << endl;

}

int main() {
    auto result =  generateTrees(3);
    cout << result.size() << endl;
    for (auto res : result){
	printBST(res);
    }
}
