//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool dfs(int start,vector<int>adj[], int vis[],int adj_color){
    
    vis[start]=adj_color;
    
    for(auto in:adj[start]){
        if(vis[in]==-1){
            // please go and color the opposite color that I have
           if( dfs(in,adj,vis,!adj_color)==false)return false;
        }
        else{
            if(vis[in]==adj_color)return false;
        }
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int vis[V];
	    for(int i=0;i<V;i++)vis[i]=-1;
	    // for connected componts
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	                 if(dfs(i,adj,vis,0)==false)return false;
	        }
       
	    }

	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends