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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(!head->next || right == left)
           return head ; 
        ListNode temp(0) ; 
        temp.next = head ; 
        ListNode* prv = &temp ; 
        right = right - left ; 
        --left ; 
        while(left--)
        {
            prv = prv->next ; 
        }
        
        ListNode* cur = prv->next ; 
        ListNode* Next = cur->next ; 
        while(right--){
           cur->next = Next->next;
            Next->next = prv->next;
            prv->next = Next;
            Next = cur->next;   
        }
        return temp.next ; 
        
    }
};