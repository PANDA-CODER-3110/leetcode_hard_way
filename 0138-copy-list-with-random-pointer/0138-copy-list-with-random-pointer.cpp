/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    
    Node *create_and_link(Node * head)
    {
        Node* forward = NULL  ; 
        Node *i = NULL ; 
        // to create the link next node 
        for(i = head ; i!=NULL ; i = i->next->next)
        {
            Node* newnode = new Node(i->val) ;
            forward = i->next ; 
            i->next = newnode ; 
            newnode->next = forward ; 
        }
        
        // to link the arbitary node 
        for(i = head ; i!=NULL ; i= i->next->next)
        {
            if(i->random!=NULL)
            {
                i->next->random= i->random->next ; 
            }
        }
        return head ; 
        
    }
    Node * sep(Node* head)
    {
        Node * res = head->next ; 
        Node* temp = res ; 
        for(Node* i = head ; i!= NULL ; i= i->next)
        {
            i ->next  = temp->next ; 
            if(temp->next!=NULL)
            temp->next = temp->next->next ; 
            temp = temp->next ; 
            
        }
        return res ; 
    }
public:
    Node* copyRandomList(Node* head) {
        if(!head ) return head ; 
         head = create_and_link(head) ; 
       head = sep(head ) ; 
       return head ; 
    }
};