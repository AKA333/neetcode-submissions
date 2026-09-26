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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        if(a->val > b->val)
            return mergeTwoLists(b, a);
        ListNode* head = a;
        ListNode* cur= NULL;
        ListNode* prev= NULL;
        
        while(a && b){
            if(cur== NULL){
                cur= a;
                a= a->next;
                continue;
            }
            if(a->val <= b->val){
                ListNode* t= a->next;
                cur->next = a;
                cur = a;
                a= t;
                // a= a->next;
            }
            else{
                ListNode* t= b->next;
                cur->next = b;
                cur = b;
                b= t;
            }
        }
        if(a){
            cur->next = a;
        }
        if(b){
            cur->next =b;
        }
        return head;
    }
};
