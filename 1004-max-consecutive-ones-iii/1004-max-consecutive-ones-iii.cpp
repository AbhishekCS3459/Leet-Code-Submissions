class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,ct=0,mx=0;
        while(j<nums.size()){
            if(nums[j]==0)ct++;
            
            if(ct==k+1){
                mx=max(mx,j-i);
                while(ct==k+1){
                
                    if(nums[i]==0)ct--;
                    i++;
                }
            }
            j++;
            
        }
        
        if(ct<k+1){
            mx=max(mx,j-i);
        }
        
        return mx;
    }
};