class Solution {
public:
    vector<int>next_greater(vector<int>&nums){
        stack<int>s;
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--){
            if(s.empty())ans.push_back(-1);
            else if(!s.empty()&& s.top()>nums[i])
                ans.push_back(s.top());
            else if(!s.empty()&& s.top()<=nums[i]){
                while(!s.empty()&& s.top()<=nums[i])s.pop();
                if(s.empty())ans.push_back(-1);
                else
                    ans.push_back(s.top());
            }
            
            s.push(nums[i]);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    unordered_map<int,int>next_greater_right(vector<int>&nums2){
         unordered_map<int,int>m;
        vector<int>ans=next_greater(nums2);
        for(int i=0;i<ans.size();i++){
            m[nums2[i]]=ans[i];
        }
        return m;
        
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        auto m = next_greater_right(nums2);
        for(auto in:m)cout<<in.first<<" "<<in.second<<endl;
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int x = m[nums1[i]];
            ans.push_back(x);
        }
        
        return ans;
    }
};