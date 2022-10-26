//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    // for the even size the middle element is n/2+1
    //Function to delete middle element of a stack.
   void delete_k(stack<int>&s,int mid,int ct){
       if(ct==mid){
           int t=s.top();
           s.pop();
           return;
       }
       int t=s.top();
       s.pop();
       ct++;
       delete_k(s,mid,ct);
       s.push(t);
       return;
   }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        // if(sizeOfStack%2!=0){
            int mid=sizeOfStack/2;
         delete_k(s,mid,0);
        // }
        // else
        //  {
        // int mid=(sizeOfStack/2)+1;
        //  delete_k(s,mid,0);
        //  }
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends