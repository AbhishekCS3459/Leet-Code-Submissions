//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
      vector<int>ans;
      map<int,bool>visdfs;
  void dfs(int starting_nd,vector<int>adj[])
    {
        if (visdfs[starting_nd])
            return;
            
        visdfs[starting_nd] = true;
        ans.push_back(starting_nd);
        for (auto in : adj[starting_nd])
        {
            if (!visdfs[in])
            {
                dfs(in,adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {

     dfs(0,adj);
     return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends