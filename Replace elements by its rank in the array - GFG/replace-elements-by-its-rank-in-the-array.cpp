//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
class node{
    public:
    int data;
    int idx;
    node(int data, int idx){
        this->data=data;
        this->idx=idx;
    }
};
class compare{
  public:
  bool operator()(node*a,node*b){
  return a->data>b->data;
      
  }
};
    vector<int> replaceWithRank(vector<int> &arr, int N){

         priority_queue<node*,vector<node*>,compare>pq;
         for(int i=0;i<N;i++)
             pq.push(new node(arr[i],i));
             
             int ct=0,t=INT_MIN;
             while(!pq.empty()){
                 auto tp=pq.top();
                 pq.pop();
                 ct++;
                 if(t==tp->data)
                 ct--;
                 t=tp->data;
                 int id=tp->idx;
                 arr[id]=ct;
             }
             return arr;
             
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends