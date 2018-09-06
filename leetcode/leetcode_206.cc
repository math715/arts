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


ListNode* reverseList(ListNode* head) {
    ListNode *p = head;
    ListNode *result = nullptr;
    while (p != nullptr) {
	ListNode *t = new ListNode(p->val);
	t->next = result;
	result = t;
	p = p->next;

    }
    return result;

}

int main( int argc, char *argv[] ) {
    ListNode *t = new ListNode(1);
    t->next = new ListNode(2);
    auto result = reverseList(t);
    cout << result->val << " " << result->next->val << endl;

    return 0;
}
