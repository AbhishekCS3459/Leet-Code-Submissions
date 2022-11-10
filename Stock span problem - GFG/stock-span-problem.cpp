//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    stack<pair<int,int>>st;
    vector<int> next_greater_right(int price[], int n)
{
    vector<int> val;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
            val.push_back(-1);
        else if (!st.empty() && st.top().first > price[i])
        {
            val.push_back(st.top().second);
        }
        else if (!st.empty() && st.top().first <= price[i])
        {
            while (!st.empty() && st.top().first <= price[i])
                st.pop();

            if (st.empty())
                val.push_back(-1);
            else
                val.push_back(st.top().second);
        }

        st.push({price[i],i});
    }
return val;
}
    
    
    
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
 auto ans=  next_greater_right(price,n);
       vector<int>final;
       for(int i=0;i<ans.size();i++){
           int x=ans[i];
           final.push_back(i-x);
       }return final;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends