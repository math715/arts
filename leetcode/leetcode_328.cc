#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	ListNode *odd = head;
	ListNode *evenHead = head->next;
	ListNode *even = evenHead;
	while(even && even->next)
	{
		odd->next = even->next;
		even->next = even->next->next;
		odd = odd->next;
		even = even->next;
	}
	odd->next = evenHead;
	return head;

}


int main() {
}
