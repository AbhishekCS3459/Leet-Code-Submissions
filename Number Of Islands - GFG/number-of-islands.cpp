//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
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
 int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

  public:
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    
vector<int>ans;
 vector<vector<int>>vis(n,vector<int>(m,0));
 
 int ct=0;
 
 DisjointSet ds(n*m);
 
for(auto in:operators){
    
    int row=in[0],col=in[1];
    
    if(vis[row][col]==1){
        ans.push_back(ct);
        continue;
        
    }
    
    else{
        vis[row][col]=1;
        ct++;
        
        for(int i=0;i<4;i++){
            
            int nx=dx[i]+row;
            int ny=dy[i]+col;
            
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&vis[nx][ny]==1){
                
                int curr_num=row*m+col;
                int adj_num=nx*m+ny;
                
                if(ds.find(adj_num)!=ds.find(curr_num)){
                    ct--;
                    ds.Union(curr_num,adj_num);
                }
            }
        }
    }
    
    ans.push_back(ct);
}
 return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends