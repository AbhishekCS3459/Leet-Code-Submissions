class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      
      unordered_map<int,int>m;

       int sum = 0;
      int n=nums.size();
       int ct=0;
   for (int i = 0; i < n; i++)
  {
    sum+=nums[i];
     // if prefix sum - k is present in map then ct++
     if(sum==k)ct++;
     if(m.find(sum-k)!=m.end()){
          ct+=m[sum-k];
        }
     m[sum]++;
  }
    

      return ct;
    }
};