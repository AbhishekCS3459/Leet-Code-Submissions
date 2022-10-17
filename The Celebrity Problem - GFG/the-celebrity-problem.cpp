//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    bool is_deserving(int top,vector<vector<int> >& M, int n){
       // for deserving it has all row 0
       bool flag=true;
       for(int i=0;i<n;i++)
           if((M[top][i]) ||(i!=top && !M[i][top]) || M[top][top] )flag=false;
         
           
       
       return flag;
       
    }
    bool a_knows_b(int a,int b,vector<vector<int> >& M, int n){
        if(M[a][b]==1)return true;
        else
        return false;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        // there are n persons
        // ith person knows jth persons if M[i][j]==1
        stack<int>s;
        for(int i=0;i<n;i++){
    // let suppose A,B,C are three persons so by inserting them all we will do below operations
            s.push(i);  
        }
        while(s.size()!=1){
            // pop a and b and check weather a know b or vice versa
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(a_knows_b(a,b,M,n)){
                // then a cannot be the clebrity
                s.push(b);
                
            }
            else
            s.push(a);
        }
        // now we have only one element in the stack which may be the possible candidate for the clebrity
        int possible_candidate_for_clebrity=s.top();
        //if all the clebrity row are 0 and all column are one except the candidate column
        
        if(is_deserving(s.top(),M,n))return s.top();
        else
        // for(int i=0;i<n;i++){
        //     if((i!=s.top() )&& (!M[i][s.top()]) || M[s.top()][i] )return -1;

        // }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends