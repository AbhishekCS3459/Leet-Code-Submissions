class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<vector<int>>ans;
        vector<int>one_row,one_col;
      int row=grid.size();
      int col=grid[0].size();
      for(int i=0;i<row;i++){
        int ct=0;
        for(int j=0;j<col;j++){
          if(grid[i][j]==1)ct++;
        }
        one_row.push_back(ct);
      }
         for(int i=0; i<col; i++) {
            int ct = 0;
            for(int j=0; j<row; j++) {
                if(grid[j][i]) ct++;
              
            }
            one_col.push_back(ct);
            
        }
    
      for(int i=0;i<row;i++){
        vector<int>temp;
        for(int j=0;j<col;j++){
          int x=one_row[i]+one_col[j]-(row-one_row[i])-(col-one_col[j]);
          cout<<x<<" ";
          temp.push_back(x);
        }
        ans.push_back(temp);
      }
      return ans;
      
    }
};