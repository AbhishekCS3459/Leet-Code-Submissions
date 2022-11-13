class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
      
         while(columnNumber){
             int r=columnNumber%26;
            if(r==0)
                r=26;
                ans.push_back('A'+(r-1));
             columnNumber/=26;
             if(r==26)
                 columnNumber--;
         }
         
         reverse(ans.begin(),ans.end());
     
        return ans;
    }
};