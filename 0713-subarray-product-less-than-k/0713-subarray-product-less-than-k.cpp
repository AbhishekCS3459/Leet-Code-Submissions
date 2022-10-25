class Solution {
public:
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		
		// as all numbers in the array are positive
        if(k <= 1) return 0;
        
        int prod = 1, res = 0, i = 0;
        int j=0;
        while( j < nums.size()) {
            prod *= nums[j];
    
            while(prod >= k) {
                prod /= nums[i];
                i++;
            }
			

			
            res += j - i + 1;
            j++;
        }
        return res;
    }
};