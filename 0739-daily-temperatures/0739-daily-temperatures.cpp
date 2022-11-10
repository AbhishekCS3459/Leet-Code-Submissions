class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
int n=temperatures.size();
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            ans.push_back(-1);
        else if (!s.empty() && s.top().first > temperatures[i])
        {
            ans.push_back(s.top().second);
        }
        else if (!s.empty() && s.top().first <= temperatures[i])
        {

            // either we got the nearest greater or we got an empty element
            while (!s.empty() && s.top().first <= temperatures[i])
            {
                s.pop();
            }
            if (s.size() == 0)
                ans.push_back(-1);
            else
            {
                ans.push_back(s.top().second);
            }
        }
        s.push({temperatures[i],i});
    }
    reverse(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i]==-1)ans[i]=0;
            else
                ans[i]=ans[i]-i;
        }
        
        return ans;
    }
};