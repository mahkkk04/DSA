/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,bool>visited;
        while(head!=nullptr){
            if(visited.find(head)!=visited.end())
            return true;
            visited[head]=true;
            head=head->next;

        }
        return false;
    }
};
*/
//optimized version
//Floyd’s Cycle Detection (Tortoise & Hare)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head->next)return false;
        ListNode* first=head;
        ListNode* second=head;
        while(first!=nullptr&&first->next!=nullptr){
           first=first->next->next;
           second=second->next;
           if(first==second)return true;

        }
        return false;

    }
};
