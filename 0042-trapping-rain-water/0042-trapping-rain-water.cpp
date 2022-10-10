class Solution {
public:
    vector<int>maximum_at_left(vector<int>&arr){
    int mx=arr[0];
    int n=arr.size();
    vector<int>ans;
   ans.push_back(arr[0]);
   for (int i = 1; i < n; i++)
   {
    mx=max(mx,arr[i]);

    ans.push_back(mx);
   }
   
    return ans;
}
    vector<int>maximum_at_right(vector<int>&arr){
   int n=arr.size();
    vector<int>ans;
    int mx=arr[n-1];
    for (int i = n-1; i >=0; i--)
    {
        mx=max(mx,arr[i]);
        ans.push_back(mx);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}

    int trap(vector<int>& height) {
         vector<int>water;
    int sum=0;
        auto l=maximum_at_left(height);
        auto r=maximum_at_right(height);
// water[i]=min(r[i],l[i])-arr[i]
for (int i = 0; i < height.size(); i++)
{
    sum+=min(l[i],r[i])-height[i];
    
}

    return sum;
        
    }
};