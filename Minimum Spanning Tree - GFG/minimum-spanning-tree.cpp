//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	class node{
	  public:
	  int dist;
	  int val;
	  int parent;
	  node(int dist,int val,int parent){
	      this->dist=dist;
	      this->val=val;
	      this->parent=parent;
	  }
};
class Compare{
    public:
    bool operator()(node*a,node*b){
        return a->dist>b->dist;
    }
};
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<node*,vector<node*>,Compare>pq;
        pq.push(new node(0,0,-1));
        vector<int>vis(V,0);
        vector<pair<int,int>>mst;
        int sum=0;
        while(!pq.empty()){
            int curr_val=pq.top()->val;
            int curr_dis=pq.top()->dist;
            int par=pq.top()->parent;
            pq.pop();
            // if the node is visited already then skip all operation
            if(vis[curr_val]==1){
                continue;
            }
            vis[curr_val]=1;
            sum+=curr_dis;
            
            mst.push_back({curr_val,par});
            for(auto in:adj[curr_val]){
                int new_val=in[0];
                int new_wt=in[1];
                if(vis[new_val]==0){
                    pq.push(new node(new_wt,new_val,curr_val));
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends