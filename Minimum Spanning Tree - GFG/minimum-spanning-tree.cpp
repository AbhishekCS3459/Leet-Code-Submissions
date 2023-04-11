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
class compare{
    public:
  bool operator()(node*a,node*b){
      return a->dist>b->dist;
  }  
};
//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
      priority_queue< node* , vector<node*>, compare >pq;

        vector<int>vis(V,0);
        vector<pair<int,int>>mst;
        
        pq.push(new node(0,0,-1));
        
        int sum=0;
        
        while(!pq.empty()){
          int dis=pq.top()->dist;
          int nd=pq.top()->val;
          int par=pq.top()->parent;
          
          
            pq.pop();
            if(vis[nd]==1)continue;
            
            vis[nd]=1;
            sum+=dis;
            
            for(auto in:adj[nd]){
                
                int adjnode=in[0],new_dist=in[1];
                
                if(vis[adjnode]==0)
                pq.push(new node(new_dist,adjnode,nd));
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