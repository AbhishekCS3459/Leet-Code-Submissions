//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<bits/stdc++.h>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    int make_digit(Node*head){
        if(!head)return 0;
        int ans=0,i=0;
        auto temp=head;
        while(temp!=NULL){
            ans+=(int)pow(10,i)*temp->data;
            i++;
            temp=temp->next;
        }
        return ans;
    }
   Node* reverseList( Node *head)
    {
        // code here
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;
         Node*tail=head->next;
         Node*reverse_lakede=reverseList(head->next);
         head->next=NULL;
         tail->next=head;
         return reverse_lakede;
    }
    bool isPalindrome(Node *head)
    {
      int number1= make_digit(head);
      
       auto h1=reverseList(head);
       
      int number2= make_digit(h1);
       return number1==number2;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends