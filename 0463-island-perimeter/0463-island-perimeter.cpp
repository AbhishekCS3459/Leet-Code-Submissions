class Solution {
public:
    int dfs(vector<vector<int>> & grid,int i, int j)
    {
        // if we are out of the grid, or we have already been at this cell, or the value is zero return,
        if( i < 0 || j < 0 || i > grid.size()-1 
       || j > grid[0].size()-1 || !grid[i][j] || grid[i][j] == 2) return 0 ; 
       
        grid[i][j] = 2; // used to track if we already visited this cell 
        int ans = 4; 
        
        if(i < grid.size() - 1 && grid[i+1][j])ans--; // checks if top == 1 
        if(j < grid[0].size() -1 && grid[i][j+1])ans--;//checks if right == 1 
        
        if(j > 0 && grid[i][j-1])ans--; // checks if left == 1 
        if(i > 0 && grid[i-1][j])ans--; // checks if bottom == 1 
        
        // dfs the left, right ,top , and bottom
        return ans + (dfs(grid, i + 1 ,j) + dfs(grid,i-1,j) + dfs(grid,i,j-1) + dfs(grid,i,j+1)); 
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0 , row = grid.size(), col = grid[0].size();    
        for(int i = 0 ; i < row ; i++)
        {
           for(int j = 0 ; j < col ; j++)
           {
               if( grid[i][j])
               {
                 return dfs(grid,i,j);  
               }
           } 
        }
        return ans;
    }
};