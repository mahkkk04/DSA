class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

priority_queue<ListNode*, vector<ListNode*>,function<bool(ListNode*, ListNode*)>> pq([](ListNode* a, ListNode* b) {
            return a->val > b->val; // min heap
        });

        // Push first node of each list
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        ListNode* dummy = new ListNode(1);
        ListNode* tail = dummy;

        // Process heap
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};
