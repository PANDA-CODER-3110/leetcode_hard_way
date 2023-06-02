//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
Node* reverseList(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    
    while(curr) {
        next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    
    return prev;
    
}

Node* mergeList(Node* l1, Node* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    while(l1 != NULL && l2 != NULL) {
        if(l1->data <= l2->data) {
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        else {
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
        
    }
    
    while(l1 != NULL) {
        temp->next = l1;
        temp = l1;
        l1 = l1->next;
    }
    
    while(l2 != NULL) {
        temp->next = l2;
        temp = l2;
        l2 = l2->next;
    }
    
    return ans->next;
}

void sort(Node **head)
{
    Node* inc = (*head);
    Node* dec = (*head)->next;
    Node* d = dec;
    
    while(dec && dec->next) {
        inc->next = inc->next->next;
        dec->next = dec->next->next;
        
        inc = inc->next;
        dec = dec->next;
    }
    
    inc->next = NULL;
    *head = mergeList(*head, reverseList(d));
}