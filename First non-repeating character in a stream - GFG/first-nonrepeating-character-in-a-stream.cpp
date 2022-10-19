//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		 unordered_map<char,int>m;
		 queue<char>q;
		 string s="";
		 for(int i=0;i<A.length();i++){
		     m[A[i]]++;
		     q.push(A[i]);

		     while(!q.empty()&&m[q.front()]>1 ){
              
              q.pop();
		     }
		   
		     if(!q.empty())s.push_back(q.front());
		     else
		     s.push_back('#');
		 }
		 return s;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends