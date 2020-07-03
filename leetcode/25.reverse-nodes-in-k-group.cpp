/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *node = nullptr, *last_end = nullptr, *last_head = nullptr;
        while (head != nullptr) {
                ListNode *tb = nullptr, *te = nullptr, *p = nullptr, *q = nullptr;
                ListNode *ptr = head;
                int left_out = 0;
                for (int i = 0; i < k; ++i) {
                        if (head == nullptr) {
                                left_out = 1;
                                break;
                        }
                        q = new ListNode(head->val);
                        head = head->next;
                        if (te == nullptr) {
                                te = q;
                        }
                        q->next = p;
                        p = q;
                }
                if (left_out == 0) {
                        tb = q;
                        if (node == nullptr) {
                                node = tb;
                        } else {
                                last_end->next = tb;
                        }
                        last_end = te;
                } else {
                        if (node == nullptr) {
                                node = ptr;
                        } else {
                                last_end->next = ptr;
                        }
                }
        }
        return node;

        
    }
};
// @lc code=end

