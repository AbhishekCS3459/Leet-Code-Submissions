//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code herem
        map<int,int>mp;
        for(int i=0;i<n;i++){
           mp[arr[i]]++;
        }
        pair<int,int>ans={-1,1e9};
        
        for(auto in:mp){
            if(in.first>=ans.first&&in.second<=ans.second){
                ans={in.first,in.second};
            }
        }
        return ans.first;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends