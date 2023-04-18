//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // make a dsu data structure
class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int v)
    {
        if (parent[v] == v)
            return v;
        // compression
        return parent[v] = find(parent[v]);
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

	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>> >edges;
        for(int i=0;i<V;i++){
            for(auto in:adj[i]){
                int v=in[0];
                int wt=in[1];
                edges.push_back({wt,{i,v}});
            }
        }
        sort(edges.begin(),edges.end());
        // cout<<edges[0].first<<endl;
         int MST_SUM=0;
         DisjointSet d1(V);
       
             for(auto in:edges){
                 int wt=in.first;
                 int u=in.second.first;
                 int v=in.second.second;
                 if(d1.find(v)!=d1.find(u)){
                     d1.Union(u,v);
                     MST_SUM+=wt;
             }
         }
         return MST_SUM;
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