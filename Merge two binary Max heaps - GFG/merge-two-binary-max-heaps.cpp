//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    //method 1
    // vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    //     priority_queue<int>q;
    //     vector<int>ans;
    //     // insertion takes log(n) time
    //     for(auto in:a){
    //         q.push(in);
    //     }
    //       for(auto in:b){
    //         q.push(in);
    //     }
    //     // deletion takes log(n) time 
    //       while(!q.empty()){
    //           int t=q.top();
    //           q.pop();
    //           ans.push_back(t);
    //       }
    //       return ans;
    // }
    //method 2
    void heapify(vector<int>&arr,int i,int n){
        int lar=i;
        int l=2*i+1,r=2*i+2;
        if(l<n&&arr[l]>arr[lar])
        lar=l;
        if(r<n&&arr[r]>arr[lar])
        lar=r;
        if(lar!=i)
        {
            swap(arr[lar],arr[i]);
            heapify(arr,lar,n);
        }
        
    }
    void build_heap(vector<int>&arr,int n){
        for(int i=(n/2)-1;i>=0;i--){
            heapify(arr,i,n);
        }
    }
      vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // vector<int>ans;
        for(auto in:b)
        {
            a.push_back(in);
        }
        
        build_heap(a,n+m);
          return a;
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

// } Driver Code Ends