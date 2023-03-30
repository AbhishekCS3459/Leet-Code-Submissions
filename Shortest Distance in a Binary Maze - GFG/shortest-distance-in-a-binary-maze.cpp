//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
class Solution {
    public:

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         //we don't need the priortiy queue to prioritise the distance as all have unit distance
    if(source.first==destination.first&&source.second==destination.second)return 0;
     int n=grid.size();
     int m=grid[0].size();
     
    vector<vector<int>>distance(n,vector<int>(m,1e9));
    
    
    distance[source.first][source.second]=0;
    
    queue<pair<int,pair<int,int>>>pq;
    pq.push({0,{source.first,source.second}});
    
    while(!pq.empty()){
        auto top_most=pq.front();
        
        pq.pop();
        
        int initial_dist=top_most.first;
        
        int initial_x=top_most.second.first;
        
        int initial_y=top_most.second.second;
        
        for(int i=0;i<4;i++){
            
            int new_x=initial_x+dx[i];
            
            int new_y=initial_y+dy[i];
            
if(new_x>=0 && new_x<n && new_y<m && new_y>=0 && grid[new_x][new_y]==1 && initial_dist+1<distance[new_x][new_y]){
                
                distance[new_x][new_y]=initial_dist+1;
                
                if(new_x==destination.first && new_y==destination.second)return initial_dist+1;
                 
                 pq.push({initial_dist+1,{new_x,new_y}});
            }
        }
        
    }
    return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends