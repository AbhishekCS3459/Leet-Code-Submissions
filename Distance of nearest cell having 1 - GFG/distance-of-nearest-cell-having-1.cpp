//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    int deltax[4]={-1,0,+1,0};
    int deltay[4]={0,1,0,-1};
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	        queue<pair<pair<int,int>,int>>q;
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    	vector<vector<bool>>vis(n,vector<bool>(m,false));
	    	
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==1){
               q.push({{i,j},0});
                   vis[i][j]=true;
               }
                
            }
        }
        
	       while(!q.empty()){
	           
            int x_ax = q.front().first.first;
            int y_ax = q.front().first.second;
            int count = q.front().second;
            
            q.pop();
            ans[x_ax][y_ax] = count;
            // search in all four direction of x and y
            for(int i=0;i<4;i++){
                    int new_x = x_ax + deltax[i];
                    int new_y = y_ax + deltay[i];
         if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && !vis[new_x][new_y] )
              {
               vis[new_x][new_y]=true;
               q.push({{new_x,new_y},count+1});
                  
              }
     }
            
      }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends