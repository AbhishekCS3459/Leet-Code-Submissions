//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        // duch flag alogrithm
        int low=0,high=n-1,mid=low;
        while(mid<=high){
            // mid ensures that there will be 0 from 0 to low-1 idx
            if(arr[mid]==0){
                swap(arr[mid],arr[low]);
                low++;
                mid++;
            }else if(arr[mid]==1){
                mid++;
            }else{
                 swap(arr[mid],arr[high]);
                high--;
            }
            // and high ensures that there will be 2 from mid+1 to n-1 idx
        }return;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends