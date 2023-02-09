//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    class node{
        public:
        int data,row,col;
        node(int data,int i,int j){
            this->data=data;
           this-> row=i;
            this->col=j;
        }
    };
    class compare{
        public:
        bool operator()(node*a, node*b){
          return a->data > b->data;
      }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
            vector<int> ans;
            priority_queue<node*,vector<node*>,compare>pq;
        // we need the first element of  all the arrrays
        for(int i=0;i<K;i++){
            node*n1=new node(arr[i][0],i,0);
            pq.push(n1);
        }
        
        while(!pq.empty()){
            auto tp=pq.top();
            ans.push_back(tp->data);
            pq.pop();
            
            int row=tp->row;
            int col=tp->col;
            
            if(col+1<arr[row].size()){
                node*n2=new node(arr[row][col+1],row,col+1);
                pq.push(n2);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends