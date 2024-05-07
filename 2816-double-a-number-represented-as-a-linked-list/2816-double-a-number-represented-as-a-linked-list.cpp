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
    void insertAtFront(ListNode*& head, int data) {
    ListNode* newNode = new ListNode();
    newNode->val = data;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}
    ListNode* stackToLinkedList(stack<int>& stk) {
    ListNode* head = nullptr;
    while (!stk.empty()) {
        int data = stk.top();
        stk.pop();
        insertAtFront(head, data);
    }
    return head;
}
    ListNode* doubleIt(ListNode* head) {
        stack<int>stk;
        while(head!=NULL){
            stk.push(head->val);
            head = head -> next;
        }
        int rem = 0;
        stack<int>newstk;
        while(!stk.empty()){
            int top = stk.top(); 
            stk.pop();
            int n = (top*2)%10;
            newstk.push(n + rem);
            if(top*2>9) rem = 1;else rem = 0;
        } 
        if(rem>0) newstk.push(rem);    
        return stackToLinkedList(newstk);
    }
};