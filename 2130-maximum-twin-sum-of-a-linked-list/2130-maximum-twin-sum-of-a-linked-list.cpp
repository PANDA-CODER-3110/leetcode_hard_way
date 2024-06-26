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
    int pairSum(ListNode* head) {
         ListNode* slow=head;
        ListNode* fast=head;

        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* forward = NULL ; 
        ListNode* prev = NULL ; 
        while(slow)
        {
            forward = slow->next ;  
            slow->next = prev ; 
            prev= slow ; 
            slow = forward ; 
        }
        int maxval= 0; 
        while(prev)
        {
            maxval = max(maxval , prev->val+head->val) ; 
            prev = prev->next ; 
            head = head->next; 
        }
        return maxval ; 
    }
};