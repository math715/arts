#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode *result = nullptr, *root = nullptr, *p = head;
    while (p != nullptr) {
	if (p->val != val) {
	    if (result == nullptr){
		result = new ListNode(p->val);
		root = result;
	    } else {
		result->next = new ListNode(p->val);
		result = result->next;
	    }
	}
	p = p->next;
    }

    return root;
}
int main( int argc, char *argv[] ) {
    ListNode *head = new ListNode(1);
    ListNode *r = head;
    r->next = new ListNode(2); r = r->next;
    r->next = new ListNode(6); r = r->next;
    r->next = new ListNode(3); r = r->next;
    r->next = new ListNode(4); r = r->next;
    r->next = new ListNode(5); r = r->next;
    r->next = new ListNode(6); r = r->next;
    auto result = removeElements(head, 6);
    r = result;
    while ( r!= nullptr) {
	cout << r->val << " ";
	r = r->next;
    }
    cout << endl;
    return 0;
}
