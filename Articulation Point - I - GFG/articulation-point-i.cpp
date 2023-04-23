//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
     int timer=0;
    
  public:
  void dfs(int node,int parent,vector<int>adj[],vector<int>&low,vector<int>&disc,vector<int>&vis,vector<int>&par,vector<int>&mark){
      vis[node]=1;
      low[node]=disc[node]=timer;
      timer++;
      int child=0;
      for(auto in:adj[node]){
          if(in==parent)continue;
          
          if(!vis[in]){
              dfs(in,node,adj,low,disc,vis,par,mark);
              low[node]=min(low[in],low[node]);
              // check for the articulation point
              if(low[in]>=disc[node]&&parent!=-1){
                  mark[node]=1;
              }
                 child++;
          }else{
                low[node]=min(low[node],disc[in]);
          }
      }
      // checking for the extra conditon
      if(parent==-1 && child>1)
      mark[node]=1;
  }
  
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
    vector<int>low(V,-1),disc(V,-1),vis(V,0),par(V,-1);
      // given adj list perform dfs
       vector<int>mark(V,0);
      for(int i=0;i<V;i++){
          if(vis[i]==0){
              dfs(i,-1,adj,low,disc,vis,par,mark);
          }
      }
      
      vector<int>ans;
for(int i=0;i<V;i++){
    if(mark[i]==1){
        ans.push_back(i);
    }
}
if(ans.size()==0)return {-1};
      return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends