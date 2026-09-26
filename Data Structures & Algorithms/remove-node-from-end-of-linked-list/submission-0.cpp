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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        ListNode* cur= head;
        int c=n;
        while(c && cur){
            cur = cur->next;
            c--;
        }
        ListNode* t= head;
        ListNode* prev= NULL;
        c=0;
        if(!cur){
            t= head->next;
            head->next= NULL;
            return t;
        }
        while(cur){
            prev= t;
            t= t->next;
            cur = cur->next;
        }
        ListNode* temp = t->next;
        prev->next = temp;
        // del(t);
        
        return head;

    }
};
