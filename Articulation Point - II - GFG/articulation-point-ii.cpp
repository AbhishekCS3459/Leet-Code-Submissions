//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int timer=0;
 
 void dfs(int start,vector<int>&vis,vector<int>&dis,vector<int>&low,
 vector<int>adj[],int parent,vector<bool>&articulation){
   vis[start]=1;
   dis[start]=low[start]=timer++;
   int children=0;
      for(auto nbr:adj[start]){
        if(nbr==parent)continue;
        
        if(vis[nbr]==0){
          dfs(nbr,vis,dis,low,adj,start,articulation);
          low[start]=min(low[start],low[nbr]);
          if(dis[start]<=low[nbr]&&parent!=-1){
           articulation[start]=true;
          }
          children++;
        }else {
              low[start]=min(low[start],dis[nbr]);
        }}
     if(parent==-1&&children>1)
     articulation[start]=true;
     
 }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
         vector<int>vis(V,0),disc(V,0),low(V,0);
        vector<bool>articulation(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==0)
             dfs(i,vis,disc,low,adj,-1,articulation);
        }
           vector<int>ans;
        for(int i=0;i<V;i++){
            if(articulation[i])ans.push_back(i);
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