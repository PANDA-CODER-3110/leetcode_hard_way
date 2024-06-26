//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        Node* even = new Node(-1) ; 
        Node* odd = new Node(-1) ; 
        Node* even_p = even ; 
        Node* odd_p = odd ; 
        Node* curr = head ;
         while(curr)
         {
             if(curr->data%2==0)
             {
                 Node * e = new Node(curr->data) ; 
                 even_p->next = e; 
                 even_p =  even_p->next ;             
                 
             }
             else
             {
                  Node * o = new Node(curr->data) ; 
                 odd_p->next = o; 
                 odd_p =  odd_p->next ; 
             }
             curr = curr->next  ; 
         }
          even_p->next = odd->next ; 
        return even->next;
         
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends