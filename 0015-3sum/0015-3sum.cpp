class Solution {
public:

  // concept lies here is that we convert the three sum into two sum by fixing one number and applying the same logic to nums
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
      vector<vector<int>>ans;
      set<vector<int>>st;
      for(int i=0;i<nums.size();i++){
        int target=-nums[i];
        int s=i+1;
        int e=nums.size()-1;
                   
        while(s<e){

          if(nums[s]+nums[e]==target){
            // we got our answer which is i,s,e
            st.insert({nums[i],nums[s],nums[e]});
            
            s++;
            e--;
          }
          else if(nums[s]+nums[e]<target){
            s++;
          }
          else
            e--;
        }
        
      }
      for(auto in:st){
        ans.push_back(in);
      }
      return ans;
    }
};