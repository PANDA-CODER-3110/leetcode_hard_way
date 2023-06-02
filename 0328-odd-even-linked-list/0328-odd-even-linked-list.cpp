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
    ListNode* oddEvenList(ListNode* head) {
         ListNode* even=new ListNode(-1);
        ListNode* even_point=even;
        ListNode* odd=new ListNode(-1);
        ListNode* odd_point=odd;
        ListNode* curr=head;
    int cnt =1 ; 
        while( curr!=NULL)
        {
            if(cnt%2==0)
            {
                ListNode* e=new ListNode(curr->val);
                even_point->next=e;
                even_point=even_point->next;
            }
            else
            {
                ListNode* o=new ListNode(curr->val);
                odd_point->next=o;
                odd_point=odd_point->next;
            }
            curr=curr->next;
            cnt++ ; 
        }
       odd_point->next = even->next ; 
        return odd->next;
    }
};