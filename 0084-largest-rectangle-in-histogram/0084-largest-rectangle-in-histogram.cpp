class Solution {
public:
    vector<int> nearest_smaller_left(vector<int> &heights)
    {
    vector<int> ans;
    stack<pair<int, int>> s;
    for (int i = 0; i < heights.size(); i++)
    {
        if (s.empty())
            ans.push_back(-1);
        else if (!s.empty() && s.top().first < heights[i])
            ans.push_back(s.top().second);
        else if (!s.empty() && s.top().first >= heights[i])
        {
            while (!s.empty() && s.top().first >= heights[i])
            {
                s.pop();
            }
            if (s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top().second);
        }

        s.push({heights[i], i});
    }
    return ans;
    }
vector<int> nearest_smaller_right(vector<int> &heights)
{
    vector<int> ans;
    stack<pair<int, int>> s;
    for (int i = heights.size() - 1; i >=0; i--)
    {
        if (s.empty())
            ans.push_back(heights.size());
        else if (!s.empty() && s.top().first < heights[i])
            ans.push_back(s.top().second);
        else if (!s.empty() && s.top().first >= heights[i])
        {
            while (!s.empty() && s.top().first >= heights[i])
            {
                s.pop();
            }
            if (s.empty())
                ans.push_back(heights.size());
            else
                ans.push_back(s.top().second);
        }

        s.push({heights[i], i});
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
            int mx=INT_MIN;
    auto left=nearest_smaller_left(heights);
    auto right=nearest_smaller_right(heights);
    int area=1;
    for (int i = 0; i < heights.size(); i++)
    {
        int l=left[i];
        int r=right[i];
        int height=heights[i];
        int width=(i-l-1)+1+(r-i-1);
        area=width*height;
        mx=max(area,mx);
    }
    
    return mx;
    }
};