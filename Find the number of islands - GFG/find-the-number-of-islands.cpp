//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>&vis){
   queue<pair<int,int>>q;
    int n=grid.size(),m=grid[0].size();
    vis[row][col]=true;
    q.push({row,col});

  while(!q.empty()){
      int x_axis=q.front().first;
      int y_axis=q.front().second;
      q.pop();


    for(int dr=-1;dr<=1;dr++){
        for(int dc=-1;dc<=1;dc++){
            int new_row=x_axis+dr;
            int new_col=y_axis+dc;

if(new_row<n && new_row>=0 &&  new_col<m && new_col>=0
 && grid[new_row][new_col]=='1'
  && !vis[new_row][new_col]){
         vis[new_row][new_col]=true;                          
         q.push({new_row,new_col});
       }
                        
    }
 }

  }

}
    int numIslands(vector<vector<char>>& grid) {
        // Code here
          int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ct=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ct++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return ct;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends