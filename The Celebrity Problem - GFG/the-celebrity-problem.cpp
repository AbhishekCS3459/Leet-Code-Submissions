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
       for(int i=0;i<n;i++){
           if(M[top][i]==1)flag=false;
          else if((i!=top && M[i][top]==0) || M[top][top]==1)
          flag=false;
          
           
           
       }
       return flag;
       
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()!=1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(M[a][b]==1)
            // means a knows b so a can't be the clebrity
            s.push(b);
            else
            s.push(a);
        }
        
        // now there is a last person which is the one of the candatite for clebrity
        
     if(is_deserving(s.top(),M,n))return s.top();
        else
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