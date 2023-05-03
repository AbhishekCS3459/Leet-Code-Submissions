//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      bool dfs(int node,int parent,vector<int> adj[],vector<int>&vis){
      if(vis[node])return false;
       
      vis[node]=1;
      for(auto in:adj[node]){
          if(vis[in]==0)
          {
              if(dfs(in,node,adj,vis))return true;
          }
          else {
          if( in!=parent)
              return true;  // point to encounter the cycle
          } 
      }
      return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
          for(int i=0;i<V;i++){
                 if(!vis[i] && dfs(i,-1,adj,vis))return true;
         }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends