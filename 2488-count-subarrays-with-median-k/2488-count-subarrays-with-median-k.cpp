class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int indexofmedian=0;
     for(int i=0;i<nums.size();i++){
       if(nums[i]==k){
         indexofmedian=i;
       break;
       }
     }
      if(indexofmedian>=nums.size())
        return -1;
      
      
      unordered_map<int,int>m;
          m[0]++;
      int diff=0;
      for(int i=indexofmedian+1;i<nums.size();i++){
        if(nums[i]>k)
          diff++;
        else
          diff--;
        
        m[diff]++;
      }

      
      diff=0;
      int ct=0;
       if(m.find(1-diff)!=m.end())
        ct+=m[1-diff];
        if(m.find(-diff)!=m.end())
        ct+=m[0-diff];
      for(int i=indexofmedian-1;i>=0;i--){
        if(nums[i]>k)diff++;
        else
          diff--;
        if(m.find(1-diff)!=m.end())
        ct+=m[1-diff];
        if(m.find(-diff)!=m.end())
        ct+=m[0-diff];
      } 
      return ct;
    }
};