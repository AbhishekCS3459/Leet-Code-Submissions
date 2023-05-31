//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	int solve(int *arr,int idx,int n,int dp[]){
	    if(idx==0){
	        // this means the idx=1 is skipped hence we reached idx=0
	        //we will take the current idx into consideration hence we are returning that
	        return arr[idx];
	    }if(idx<0)return 0;
	    // if we pick the current idx into summmation
	    // now we cannot go to the idx-1 index as it is the adj node
	     if(dp[idx-2]==-1)
	       dp[idx-2]=solve(arr,idx-2,n,dp);
	       
	    int picked=arr[idx]+dp[idx-2];
// if not picked then we can take idx-1 into our consideration
// not picking the idx means we are skipping that idx to grab the idx-1 idx so that it can be one of the possibe ans
//as it is the only way to go to the idx-1 index bcz we can't call that idx directly as adjecent is not allowed
	  if(dp[idx-1]==-1)
	      dp[idx-1]=solve(arr,idx-1,n,dp);
	     
	    int not_picked=dp[idx-1];
	     
	    return max(not_picked,picked);
	}
//optimization 1 --> tabulation
int solve_tabulation(int *arr,int idx,int n){
    int prev1=arr[0];
    int prev0=0;
    int mx=INT_MIN;
    
      for(int i=1;i<n;i++){
         int picked=arr[i];
          if(i>1)
            picked+=prev0;
            
        int not_picked=prev1;
        prev0=prev1;
        prev1=max(picked,not_picked);
      }
      return prev1;
}
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n<=1)return arr[0];
	    int idx=n-1;
	    int dp[n];
	    for(int i=0;i<n;i++){
	        dp[i]=-1;
	    }
	    return solve_tabulation(arr,idx,n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends