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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;

        for(auto i:lists){
            pq.push(i);
        }
        ListNode* head= NULL;
        ListNode* cur= NULL;

        while(!pq.empty()){
            auto t= pq.top();
            pq.pop();
            if(t->next){
                pq.push(t->next);
            }
            if(!head){
                head= t;
                cur= head;
            }
            else{
                cur->next = t;
                cur = t;
            }
        }
        return head;
    }
};
