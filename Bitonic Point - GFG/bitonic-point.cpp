//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// same as peak element
	int findMaximum(int arr[], int n) {
	    // code here
	    int s=0,mid,e=n-1;
	    if(n==1)return arr[0];
	    while(s<=e){
	        mid=s+(e-s)/2;
	        if(mid>0&&mid<n-1){
	       if(arr[mid-1]<arr[mid]&&arr[mid+1]<arr[mid])return arr[mid];
	       else if(arr[mid-1]>arr[mid])e=mid-1;
	       else s=mid+1;
	        }
	        else if(mid==0){
	            if(arr[mid]>arr[mid+1])return arr[0];
	            else return arr[1];
	        }
	        else{
             if(arr[mid]>arr[mid-1])return arr[n-1];
	            else return arr[n-2];
	        }
	    }return -1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends