class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,ct=0,mx=INT_MIN;
        while(j<nums.size()){
            if(nums[j]==0)ct++;
            
                 while(ct==1){
                    mx=max(mx,j-i);
                     if(nums[i]==0)ct--;
                     i++;
                 }

            j++;
        }
        if(ct<1)mx=max(mx,j-i);
        
        return mx;
    }
};