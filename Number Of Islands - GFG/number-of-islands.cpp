//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
class DisjointSet {
    std::vector<int> parent, size;
public:
    DisjointSet(int n) : parent(n), size(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        if (parent[v] == v)
            return v;
        return parent[v] = find(parent[v]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b])
                std::swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

};
public:
vector<int> numOfIslands(int n, int m, const vector<vector<int>>& operators) {
    vector<int> ans;
    vector<vector<bool>> vis(n, vector<bool>(m));
    DisjointSet ds(n * m);

    int ct = 0;
    for (const auto& op : operators) {
        int row = op[0], col = op[1];
        if (vis[row][col]) {
            ans.push_back(ct);
            continue;
        }
        vis[row][col] = true;
        ++ct;
        int curr_num = row * m + col;
        for (int d = 0; d < 4; ++d) {
            int nx = row + dx[d], ny = col + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny]) {
                int adj_num = nx * m + ny;
                if (ds.find(adj_num) != ds.find(curr_num)) {
                    --ct;
                    ds.unite(curr_num, adj_num);
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