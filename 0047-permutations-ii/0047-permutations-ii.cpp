class Solution {

public:
  void permutecal(vector<int>&nums,int i, vector<vector<int>>&ans){
    if(i>=nums.size())
    {
      ans.push_back(nums); 
      
    }
    unordered_set<int>m;
    for(int j=i;j<nums.size();j++){
      if(m.find(nums[j])!=m.end())
      {continue;}
      m.insert(nums[j]);
      swap(nums[j],nums[i]);
      permutecal(nums,i+1,ans);
      swap(nums[j],nums[i]);
    }
    
  }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       
      vector<vector<int>>ans;
      int i=0;
      permutecal(nums,i,ans);
      
      return ans;
    }
};