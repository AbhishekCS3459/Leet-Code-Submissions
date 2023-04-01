//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  const int m=100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
    //  unordered_set<int> st(arr.begin(), arr.end());
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,start});
        vector<int>dist(m,INT_MAX);
        vector<int>vis(m,0);
          vis[start]=1;
        while (!q.empty()) {
            // Get the next word and its count from the queue
            auto count = q.top().first;
            int currnum = q.top().second;
            q.pop();
            // If we find the end word, return the count
            if (currnum%m == end) {
                return count;
            }
            
            for(auto in:arr){
                int new_num=(currnum*in)%m;
                if(vis[new_num]==0)
               { dist[new_num]=min(dist[new_num],count+1);
                     q.push({count+1,(new_num)});
                   vis[new_num]=1;
               }
        }
            }
            return -1;
        }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends