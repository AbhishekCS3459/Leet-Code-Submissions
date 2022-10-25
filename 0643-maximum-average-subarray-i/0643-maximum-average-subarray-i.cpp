class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0;
        int mx=INT_MIN;
        int sum=0;
        while(j<nums.size()){
              sum+=nums[j];
            
            if(j-i+1<k)j++;
            
         else if(j-i+1==k){
                mx=max(mx,sum);
                sum-=nums[i];
                i++;
                j++;
            }
        }
        double c=mx;
        return c/k;
    }
};