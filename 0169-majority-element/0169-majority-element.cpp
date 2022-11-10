class Solution {
public:
//     Steps to implement the algorithm :
// Step 1 – Find a candidate with the majority –

// Initialize a variable say i ,votes = 0, candidate =-1 
// Traverse through the array using for loop
// If votes = 0, choose the candidate = arr[i] , make votes=1.
// else if the current element is the same as the candidate increment votes
// else decrement votes.
    
    
// Step 2 – Check if the candidate has more than N/2 votes –

// Initialize a variable count =0 and increment count if it is the same as the candidate.
// If the count is >N/2, return the candidate.
// else return -1.
    
    int majorityElement(vector<int>& nums) {
        // Could you solve the problem in linear time and in O(1) space?
        int candidate=-1,votes=0;
        for(int i=0;i<nums.size();i++){
            if(votes==0){
                candidate=nums[i];
                votes=1;
            }
         
            	else {
			if (nums[i] == candidate)
				votes++;
			else
				votes--;
		}
                
        }
        int d=nums.size()/2;
        int ct=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==candidate)ct++;
        }
        if(ct>d)
        return candidate;
            return -1;
        
        
    }
};