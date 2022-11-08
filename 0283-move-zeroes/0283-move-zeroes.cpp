class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ct=0;
        
        
         for(auto it=nums.begin();it!=nums.end();)
          {
          if((*it)==0){
              ct++;
              it=nums.erase(it);
              
          }
          else
              it++;
      }
        while(ct--){
            nums.push_back(0);
        }
    }
};