//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    vector<int>adj[N];
    for(auto in:edges){
        adj[in[0]].push_back(in[1]);
         adj[in[1]].push_back(in[0]);
         
    }
    
     queue<pair<int,int>>q;
     vector<int>ans(N,-1);
     vector<bool>vis(N,false);
     q.push({src,0});
     vis[src]=true;
     while(!q.empty()){
         int t=q.front().first;
         int ct=q.front().second;
         q.pop();
         for(auto in:adj[t]){
             if(!vis[in]){
                 q.push({in,ct+1});
                 vis[in]=true;
             }
         }
         ans[t]=ct;
     }
     
     
     
     return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends