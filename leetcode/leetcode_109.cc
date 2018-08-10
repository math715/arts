struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
TreeNode* sortedListToBST(ListNode* head) {
	if (head == nullptr) {
		return nullptr;
	}
	if (head->next == nullptr){
		return new TreeNode(head->val);
	}
	ListNode *big = nullptr, *small = nullptr;
	ListNode *p = head;
	int num = 0;
	while (p != nullptr){
		++num;
		p = p->next;
	}
	int mean = num / 2;
	p = head;
	for (int i = 0; i < mean - 1; ++i){
		p = p->next;
	}
	small = head;
	ListNode *r = p->next;
	p->next = nullptr;
	TreeNode *root = new TreeNode(r->val);
	big = r->next;
	root->left = sortedListToBST(small);
	root->right = sortedListToBST(big);
	return root;
}
