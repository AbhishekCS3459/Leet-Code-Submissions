//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
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
        int candidate=s.top();
        int flag=1;
        for(int i=0;i<n;i++){
            if(M[candidate][i]!=0 || ((i!=candidate) && M[i][candidate]==0))
             flag=-1;
        }
     if(flag==1)return s.top();
     else
     return flag;
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