//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        priority_queue<int,vector<int>,greater<int>>pq;  // space for all element O(n) space
      
        vector <int>ans;
          for(int i=0;i<K;i++){
            pq.push(arr[i]);   // n time insertion --> nlog(k);
        }
        
           for(int i=K;i<num;i++){
              if(pq.top()>arr[i])
               ans.push_back(arr[i]); // n time insertion --> nlog(k);
              else
              {
                  int t=pq.top();
                  ans.push_back(t);
                  pq.pop();
                  pq.push(arr[i]);
              }
       
        }
        
        while(!pq.empty()){
            int x=pq.top();
            ans.push_back(x);
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends