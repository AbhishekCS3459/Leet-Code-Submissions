//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    bool A_knows_B(int a,int b,vector<vector<int> >& M){
        if(M[a][b]==1)return true;
        else
        return false;
    }
    bool is_deserve(int dc,vector<vector<int> >& M){
        // for dc to be deserving 
        //1} row dc must be all zerro
        
        
        int ct=0;
        int flag=false;
        for(int i=0;i<M.size();i++){
            if(M[dc][i]==0)ct++;
        }
        if(ct==M.size())flag=true;
         
         
         
         
         //2) colum dc must have only 1 0 and all 1
         
         int ct_2=0;
         for(int i=0;i<M.size();i++){
             if(M[i][dc]==1)ct_2++;
             
         }
    if(flag && (ct_2==M.size()-1) && M[dc][dc]==0 )return true;
    else
    return false;
    }
    public:
    stack<int>s;
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
         for(int i=0;i<n;i++)
         s.push(i);
         while(s.size()>1){
             int a=s.top();
             s.pop();
             int b=s.top();
             s.pop();
             if(A_knows_B(a,b,M))s.push(b);
          else
          s.push(a);
             
         }
         int deserving=s.top();
         if(is_deserve(deserving,M))return s.top();
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