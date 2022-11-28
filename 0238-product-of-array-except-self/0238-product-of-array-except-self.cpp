class Solution {
public:
          vector<int>prefix,suffix;
    vector<int> productExceptSelf(vector<int>& nums) {

      int pre=1;
      prefix.push_back(1);
      suffix.push_back(1);
      int n=nums.size();
      
      for(int i=1;i<nums.size();i++){
        pre=pre*nums[i-1];
        prefix.push_back(pre);
          int suff=suffix[i-1]*nums[n-i];
        suffix.push_back(suff);
      }
      reverse(suffix.begin(),suffix.end());
      
      // ans will be equal to prefix of i and suffix of i except i in both case
      vector<int> ans;
 for(int i=0;i<n;i++){
   int x=suffix[i]*prefix[i];
   ans.push_back(x);
 }
      return ans;
    }
};