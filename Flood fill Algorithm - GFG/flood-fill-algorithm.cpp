//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int delta_row[4]={-1,0,1,0};
int delta_col[4]={0,1,0,-1};
    void Connected_cmp_bfs(int row, int col, vector<vector<int>> &image, vector<vector<bool>> &vis,int color)
    {
        queue<pair<int, int>> q;
        int n = image.size(), m = image[0].size();
       int initial_color=image[row][col];
        image[row][col]=color;
        
        vis[row][col] = true;
        q.push({row, col});
        while (!q.empty())
        {
            int x_axis = q.front().first;
            int y_axis = q.front().second;
            q.pop();

            image[x_axis][y_axis]=color;
            for (int i = 0;i< 4;i++)
            {
                    int new_row = x_axis + delta_row[i];
                    int new_col = y_axis + delta_col[i];
                    
                    if (new_row < n && new_row >= 0 && new_col < m && new_col >= 0 && image[new_row][new_col] == initial_color  && !vis[new_row][new_col])
                    {
                        // cout<<"newrow"<<new_row<<"new col"<<new_col<<endl;
                        vis[new_row][new_col] = true;
                        q.push({new_row, new_col});
                    }
                
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        //concept fill all the connected component form the starting node with the color mentioned
     int n=image.size(),m=image[0].size();
       vector<vector<bool>>vis(n,vector<bool>(m,false));
       Connected_cmp_bfs(sr,sc,image,vis,newColor);
       
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends