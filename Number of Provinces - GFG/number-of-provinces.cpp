//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  map<int,bool>vis;
  
  void dfs(int starting,vector<int>adj[],map<int,bool>&vis){
      if(vis[starting])return;
      
      vis[starting]=true;
      for(auto in:adj[starting]){
          if(!vis[in]){
              dfs(in,adj,vis);
          }
      }
      
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
       int ct=0;
       // here the adj is 0 based
       
       // make a adjlist
       vector<int>adjli[V];
       for(int i=0;i<V;i++){
          for(int j=0;j<V;j++){
              if(adj[i][j]==1 && i!=j){
                  adjli[i].push_back(j);
                  adjli[j].push_back(i);
              }
          }
       }

      for(int i=0;i<V;i++){
          if(!vis[i]){
              dfs(i,adjli,vis);
              ct++;
          }
      }
       return ct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends