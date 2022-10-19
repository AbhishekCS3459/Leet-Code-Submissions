//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
void push_k_to_end_in_reverse(queue<int>&q,int k){
    stack<int>s;
    for(int i=0;i<k;i++){
        int f=q.front();
        q.pop();
        s.push(f);
    }
    for(int i=0;i<k;i++){
        int t=s.top();
        s.pop();
        q.push(t);
    }
    return;
}
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    if(k>q.size())return q;
    push_k_to_end_in_reverse(q,k);
    int t=q.size()-k;
    while(t--){
        int s=q.front();
        q.pop();
        q.push(s);
    }
    return q;
}