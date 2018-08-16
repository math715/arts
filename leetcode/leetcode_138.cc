
#include <iostream>
#include <map>

using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == nullptr) {
		return nullptr;
	}
	map<RandomListNode *, RandomListNode *> node_map;
	RandomListNode *result = new RandomListNode(head->label);
	RandomListNode *p = head, *next = result;
	while (p->next != nullptr) {
		node_map[p] = next;
		p = p->next;
		next->next = new RandomListNode(p->label);
		next = next->next;
	}
	node_map[p] = next;

	p = head;
	next = result;
	while (p->next != nullptr){
		next->random = node_map[p->random];
		next = next->next;
		p = p->next;
	}
	next->random = node_map[p->random];
	return result;
}


int main() {
}
