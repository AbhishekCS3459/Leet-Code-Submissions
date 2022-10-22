class Solution {
    // O(N*N) SOLUTION
//             for(int i=0;i<nums.size()-k+1;i++){
//             int mx=nums[i];
            
//             for(int j=i;j<i+k;j++){
//                 mx=max(mx,nums[j]);
//             }
//             ans.push_back(mx);
//         }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>l;
        int j=0,i=0;
        while(j<nums.size()){
                  // im am poping frm back because I want to perform the decreasing order     
            while(!l.empty() && l.back()<nums[j])l.pop_back();
            l.push_back(nums[j]);
            if(j-i+1<k)j++;
            else if(j-i+1==k){
            ans.push_back(l.front());
                if(nums[i]==l.front())
                    l.pop_front();
                i++;
                j++;
            
            }
        }

        
        return ans;
    }
};