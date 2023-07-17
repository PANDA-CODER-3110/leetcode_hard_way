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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0) ; 
        ListNode* s = small; 
         ListNode* high=new ListNode(0);
       ListNode* h=high;
        while(head)
        {
            if(head->val<x){
                s->next = head ; 
                s=s->next ; 
            }
            else
            {
                h->next = head ; 
                h= h->next ; 
            }
            head= head->next ; 
        }
        h->next = NULL ; 
        s->next = high ->next ; 
        return small->next ; 
    }
};