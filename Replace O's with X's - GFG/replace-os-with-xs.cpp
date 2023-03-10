//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int deltx[4]={-1,0,0,1};
int delty[4]={0,1,-1,0};
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // same as flood fill but there is a catch of if there is boundary ignore them
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,false));
        // all border row will be pushed to queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if (i == 0 || j == 0 || i == n - 1   || j == m - 1)
              {
                  if(!vis[i][j] && mat[i][j]!='X'){
                  vis[i][j]=3;
                  q.push({i,j});
                  }

              }
            }
        }
        
        // cout<<q.size()<<endl;
        
        while (!q.empty())
        {
            int x_axis = q.front().first;
            int y_axis = q.front().second;
            q.pop();
            for (int i = 0;i< 4;i++)
            {
                    int new_row = x_axis + deltx[i];
                    int new_col = y_axis + delty[i];
                    
                    if (new_row < n-1 && new_row > 0 && new_col < m-1 && new_col > 0 && mat[new_row][new_col] != 'X'  && !vis[new_row][new_col])
                    {
                        // cout<<"newrow"<<new_row<<"new col"<<new_col<<endl;
                        vis[new_row][new_col] = 3;
                        q.push({new_row, new_col});
                    }
                
            }
        }
     for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
                  if(vis[i][j]==0 ){
                   mat[i][j]='X';
                  }
                  else
                  mat[i][j]='O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends