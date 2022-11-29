class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
      
      unordered_map<int,int>m;

       int sum = 0;
      int n=nums.size();
       int ct=0;
      int mx=0;
   for (int i = 0; i < n; i++)
  {
    sum+=nums[i];
     // if prefix sum - k is present in map then ct++
     if(sum==k)
     {
       mx=max(mx,i+1); // extra condition needed to find the largest subarray condition
     
     } 
     if(m.find(sum-k)!=m.end()){
       mx=max(mx,i-m[sum]); // extra condition needed to find the largest subarray condition
        }
     else
     m[sum]=i;
  }
    

      return mx;
    }
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]==0)nums[i]=-1;
        }
      int k=0;
return subarraySum(nums,k);
    }
};