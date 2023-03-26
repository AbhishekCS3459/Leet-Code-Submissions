//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
      bool operator()(pair<int,int>&a,pair<int,int>& b)
    {
        // Compare on basis of roll number
        if (a.first ==b.first) {
            return a.second<b.second;
        }
        return a.first<b.first;
    }
    
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // initialis pq and vector
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        
        st.insert({0,S});
        
        dist[S]=0;
        
       while(!st.empty()){
           auto front=*st.begin();
           int dist_till_curr=front.first;// 0
           int value_of_curr=front.second;// 0
           st.erase(st.begin());
           for(auto in:adj[value_of_curr]){
               int new_nd=in[0]; // 1 
               int new_weight=in[1];  // 9
               if(dist_till_curr+new_weight<dist[new_nd]){   //9+0<int_max
                  
                  if(dist[new_nd]!=INT_MAX)st.erase({dist[new_nd],new_nd});
                  
                  dist[new_nd]=dist_till_curr+new_weight;  //dist[1]=9;
                  st.insert({dist[new_nd],new_nd});   // push {9,1}
               }
           }
       }
       
       return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends