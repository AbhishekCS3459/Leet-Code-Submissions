//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	class DisjointSet{
	  public:
	  vector<int>parent,size;
	    DisjointSet(int n){
	        parent.resize(n+1);
	        size.resize(n+1);
	        for(int i=0;i<=n;i++){
	            parent[i]=i;
	            size[i]=1;
	        }
	    }
	    int find(int u){
	        if(parent[u]==u)return u;
	        return parent[u]=find(parent[u]);
	    }
	   
	   
	 void Union(int a, int b)
      {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (size[a] < size[b])
               swap(a, b); // size optimization
            parent[a] = b;
        }
     }
	};
// 	class Compare{
// 	  public:
// 	  bool operator()(Node* a,Node* b){
	      
// 	  }
// 	};
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Implementig using kuskral algo
        //sorting the edges on the basis of their wieghts using priority queue
        priority_queue<pair<int, pair<int,int>>>pq;
        for(int i=0;i<V;i++){
            for(auto in:adj[i]){
                pq.push({(-1*in[1]),{i,in[0]}});
            }
        }
        DisjointSet d1(V);
        int sum=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            pq.pop();
            if(d1.find(u)!=d1.find(v)){
                // both belong to diffrent compo
                d1.Union(u,v);
                sum+=abs(wt);
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