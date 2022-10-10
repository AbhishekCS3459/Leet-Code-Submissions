class Solution {
public:
    vector<int>nearest_smaller_left(vector<int>&nums){
    stack<pair<int,int>>s;
    vector<int>ans;
 for (int i = 0; i < nums.size(); i++)
 {
    if(s.empty())ans.push_back(-1);
    else if (!s.empty()&&s.top().first<nums[i])
    {
        ans.push_back(s.top().second);
    }
    else if (!s.empty()&&s.top().first>=nums[i])
    {
        int ct=1;
        while (!s.empty()&&s.top().first>=nums[i])
        {
            ct++;
            s.pop();
        }
        if(s.empty())ans.push_back(-1);
        else
        ans.push_back(s.top().second);
        
    }
    s.push({nums[i],i});
    
    
 }
 return ans;
 
    
}
vector<int>nearest_smaller_right(vector<int>&nums){
    vector<int>ans;
    stack<pair<int,int>>s;
    for (int i = nums.size()-1; i >=0; i--)
    {
        if(s.empty())ans.push_back(nums.size());
       else if (!s.empty()&&s.top().first<nums[i])
       {
        ans.push_back(s.top().second);
       }
       else if (!s.empty()&&s.top().first>=nums[i])
       {
        while (!s.empty()&&s.top().first>=nums[i])s.pop();
        if(s.empty())ans.push_back(nums.size());
        else
        ans.push_back(s.top().second);
        
       }
       s.push({nums[i],i});
    
    }
    reverse(ans.begin(),ans.end());
return ans;

    
}
// find nearest smaller to left and right
int maximum_area_histogram(vector<int>&nums){
    int mx=INT_MIN;
    auto left=nearest_smaller_left(nums);
    auto right=nearest_smaller_right(nums);
    int area=1;
    for (int i = 0; i < nums.size(); i++)
    {
        int l=left[i];
        int r=right[i];
        int height=nums[i];
        int width=(r-l-1);
        area=width*height;
        mx=max(area,mx);
    }
    
    return mx;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>dp;
        // first we have to push first row
        int ans=0;
        int n=matrix.size();
        if(n==0)return 0;
        vector<int>v;
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]=='1')
                v.push_back(1);
            else
                v.push_back(0);
            
        }
                dp.push_back(v);
        ans=max(ans,maximum_area_histogram(v));

        for(int i=1;i<n;i++){
            vector<int>helper;
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0')
                    helper.push_back(0);
                else{
                    helper.push_back(1+dp[i-1][j]);
                }
            }
            ans=max(ans,maximum_area_histogram(helper));
            dp.push_back(helper);
        }
        
        
        return ans;
        
    }
};