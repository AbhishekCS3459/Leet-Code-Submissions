//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int start,vector<int> adj[],   vector<bool>&vis){
        queue<pair<int,int>>q;
        q.push({start,-1});
        vis[start]=true;
        while(!q.empty()){
          auto top=q.front();
          q.pop();
          int value=top.first;
          int parent=top.second;
          for(auto in:adj[value]){
              if(!vis[in]){
                  q.push({in,value});
                  vis[in]=true;
              }
                   //   two case if it is its parent or not  
                //if it is not the parent then there must be a cycle
              else if(in!=parent){
                return true;
              }
          }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V);
         for(int i=0;i<V;i++){
                 if(!vis[i] && bfs(i,adj,vis))return true;
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