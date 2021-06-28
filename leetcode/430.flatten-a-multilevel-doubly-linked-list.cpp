/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node* h =  head;
        while (h != nullptr) {            
            auto next =  h->next;
            if (h->child != nullptr) {            
                Node *p = flatten(h->child);
                h->next = p;
                p->prev = h;
                Node *q = p;
                while (q->next != nullptr) {
                    q = q->next;
                }
                q->next = next;
                if (next != nullptr) {
                    next->prev = q;
                }
                h->child = nullptr;               
            } 
            h = next;            
        }
        return head;
        
    }
};
// @lc code=end

