/** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 **/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};

class Solution {
    public:
	static bool compare(ListNode *lhs, ListNode *rhs){
	    return lhs->val > rhs->val;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
	    ListNode *result = new ListNode(0);
	    ListNode *p = result;
	    int size = lists.size();
	    auto cmp = [](ListNode *lhs,ListNode *rhs)->bool{ return lhs->val > rhs->val; } ;
	    priority_queue<ListNode *, vector<ListNode*>, decltype(cmp) > queue(cmp);
	    for (int i = 0; i < size; ++i ){
		if (lists[i] != nullptr){
		    queue.push(lists[i]);
		}
	    }
	    while (!queue.empty()) {
		auto q = queue.top();
		// cout << q->val << endl;
		result->next = new ListNode(q->val);	
		// cout << result->next->val << endl;
		result = result->next;
		if (q->next != nullptr){
		    queue.push(q->next);
		}
		queue.pop();
	    }
	    return p->next;
	}
};


int main() {
    ListNode *val1 = new ListNode(1);
    val1->next = new ListNode(4);
    val1->next->next = new ListNode(5);
    ListNode *val2 = new ListNode(1);
    val2->next = new ListNode(3);
    val2->next->next = new ListNode(4);
    ListNode *val3 = new ListNode(2);
    val3->next = new ListNode(6);
    vector<ListNode *> vecs;
    vecs.push_back(val1);
    vecs.push_back(val2);
    vecs.push_back(val3);
    Solution solu;
    ListNode *result = solu.mergeKLists(vecs);
    while( result != nullptr) {
	cout << result->val << " ";
	result = result->next;
    }
    cout << endl;
    return 0;
}
