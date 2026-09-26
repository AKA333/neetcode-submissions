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
    bool hasCycle(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* s= head;
        ListNode* f= head->next;
        while(s && f && f->next){
            if(s==f)
                return 1;
            s= s->next;
            f= f->next->next;
        }
        return 0;
    }
};
