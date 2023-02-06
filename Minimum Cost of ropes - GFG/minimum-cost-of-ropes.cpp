//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long ans=0;
        priority_queue<long long,vector<long long>,greater<long long>>q;
        
     for(int i=0;i<n;i++){
         q.push(arr[i]);
     }
        while(q.size()>1){
            long long t1=q.top();
            q.pop();
            long long t2=q.top();
            q.pop();
            // long long sum=t1+t2;
            q.push(t1+t2);
            ans+=t1+t2;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends