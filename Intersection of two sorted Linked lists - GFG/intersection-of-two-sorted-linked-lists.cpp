//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node*h1=head1;
        Node*h2=head2;
    if(h1==NULL )return h1;
    if(h2==NULL)return h2;
    // cout<<h1->data<<" ";
    Node*dummy=new Node(-1);
    Node*temp=dummy;
    while(h1 && h2){
        if(h1->data==h2->data){
            Node*new_node=new Node(h1->data);
            temp->next=new_node;
            temp=new_node;
            h1=h1->next;
            h2=h2->next;
        }
        else if(h1->data<h2->data){
            // while(h2!=NULL && h1!=NULL && h1->data<h2->data)
            h1=h1->next;
        }
        else{
            // while(h2!=NULL && h1!=NULL && h2->data<h1->data)
            h2=h2->next;
        }
        
    }
    return dummy->next;
    
    
}