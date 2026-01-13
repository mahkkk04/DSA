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
   ListNode* merge(ListNode* a, ListNode* b) {
    ListNode d(0), *t = &d;
    while (a && b) {
        if (a->val < b->val) t->next = a, a = a->next;
        else t->next = b, b = b->next;
        t = t->next;
    }
    t->next = a ? a : b;
    return d.next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;
    ListNode* mid = slow->next;
    slow->next = nullptr;
    return merge(sortList(head), sortList(mid));
}

};