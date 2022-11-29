class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int n=nums.size();
        int prefix[n];
      int suffix[n];
      suffix[n-1]=0;
      prefix[0]=0;
      int sum=0;
      for(int i=1;i<nums.size();i++){
        prefix[i]=prefix[i-1]+nums[i-1];
        suffix[n-i-1]=suffix[n-i]+nums[n-i];
      }
      for(int i=0;i<nums.size();i++){
        if(prefix[i]==suffix[i])return i;
      }
      return -1;
    }
};