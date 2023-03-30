//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
class Solution {
    public:
    class Node{
        public:
        int x;
        int y;
        int dist;
        Node(int x,int y,int dist){
            this->x=x;
            this->y=y;
            this->dist=dist;
        }
    };
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         //we don't need the priortiy queue to prioritise the distance as all have unit distance
     int n=grid.size();
     int m=grid[0].size();
    vector<vector<int>>distance(n,vector<int>(m,1e9));
        if(source.first==destination.first&&source.second==destination.second)return 0;
    queue<Node*>pq;
    
    distance[source.first][source.second]=0;
    
    pq.push(new Node(source.first,source.second,0));
    while(!pq.empty()){
        auto top_most=pq.front();
        pq.pop();
        int initial_x=top_most->x,initial_y=top_most->y,initial_dist=top_most->dist;
        
        for(int i=0;i<4;i++){
            
            int new_x=initial_x+dx[i];
            int new_y=initial_y+dy[i];
            
if(new_x>=0 && new_x<n && new_y<m && new_y>=0 && grid[new_x][new_y]==1 && initial_dist+1<distance[new_x][new_y]){
                
                distance[new_x][new_y]=initial_dist+1;
                
                if(new_x==destination.first&&new_y==destination.second){
                 return  initial_dist+1;
                }
                
                 pq.push(new Node(new_x,new_y,initial_dist+1));
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