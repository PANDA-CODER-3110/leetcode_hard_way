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
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        
        ListNode* tmp=head;

        while(tmp){
            v.push_back(tmp->val);
            tmp=tmp->next;
        }

        vector<int> ans;
        int n=v.size();
        int gEl=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(v[i]>=gEl){
                ans.push_back(v[i]);
                gEl=max(gEl,v[i]);
            }else{
                gEl=max(gEl,v[i]);
            }
        }
        int m=ans.size();
        ListNode* newHead=NULL,*prev=NULL;
        for(int i=m-1;i>=0;i--){
            ListNode *ptr = new ListNode(ans[i]);

            if(!newHead){
                newHead=ptr;
                prev=ptr;
            }else{
                prev->next=ptr;
                prev=ptr;
            }
        }
        return newHead;
    }
};