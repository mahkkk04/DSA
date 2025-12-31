class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);          // fixed
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;   // fixed
            }
            tail = tail->next;
        }

        if (list1) tail->next = list1; // moved outside loop
        else tail->next = list2;       // fixed semicolon

        return dummy.next;
    }
};
