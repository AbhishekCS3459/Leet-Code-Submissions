class Solution {
public:
    int findGCD(vector<int>& nums) {
     int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
          mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }
return __gcd(mn,mx);
    }
};