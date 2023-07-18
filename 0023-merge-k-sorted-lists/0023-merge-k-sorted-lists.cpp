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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* lh;
        ListNode* rh;
        int n=lists.size();
        if(n == 0)
        return nullptr;

        if(n == 1)
        return lists[0];

        lh=lists[0];
        for(int i=0;i<n-1;i++){
            rh=lists[i+1];
            lh = merge(lh,rh);
        }
        return lh;
    }

    ListNode* merge(ListNode* lh,ListNode* rh){
        ListNode* dummy=new ListNode(0);
        ListNode* node;
        node = dummy;
        while(lh != NULL && rh != NULL){
            if(lh->val > rh->val){
                dummy->next = rh;
                dummy = dummy->next;
                rh = rh->next;
            }
            else{
                dummy->next = lh;
                dummy = dummy->next;
                lh = lh->next;
            }
        }
        while(lh != NULL){
            dummy->next = lh;
            dummy = dummy->next;
            lh = lh->next;
        }
        while(rh != NULL){
            dummy->next = rh;
            dummy = dummy->next;
            rh = rh->next;
        }
        return node->next;
    }
};