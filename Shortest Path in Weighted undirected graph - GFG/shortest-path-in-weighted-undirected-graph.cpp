//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // shortest path between 1 to n
        vector<pair<int,int>>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
            
        }
        
        
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>st;
        
        vector<int>dist(n+1,1e9);
        
        vector<int>parent_nodes(n+1);
        for(int i=1;i<=n;i++)
            parent_nodes[i]=i;
            
        dist[1]=0;
        
        st.push({0,1});
        
        while(!st.empty()){
            
            auto top = st.top();
            int dis = top.first;
            int value=top.second;
            
            st.pop();
            
            for(auto in:adj[value]){
                
                int curr_value=in.first;
                int wt=in.second;
                
                if(wt+dis<dist[curr_value]){
                    dist[curr_value]= wt+dis;
                    st.push({dist[curr_value],curr_value});
                    parent_nodes[curr_value]=value;
                }
            }
        }
        vector<int>ans;
        int node=n;
        if(dist[node]==1e9)return {-1};
        // time complexity --> O(n) at max 
        while(parent_nodes[node]!=node){
            ans.push_back(node);
            node=parent_nodes[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
}
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends