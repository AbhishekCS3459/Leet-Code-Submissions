//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void seive(int n,vector<bool>&primes,vector<int>&lowest_prime){
      for(int i=2;i<=n;i++){
          if(primes[i]==true){
          for(int j=2*i;j<=n;j+=i){
              primes[j]=false;
              if(lowest_prime[j]==0)
              lowest_prime[j]=i;
           }
              
        }
      }
  }
    vector<int> leastPrimeFactor(int n) {
  vector<bool>primes(n+1,true);
  primes[0]=primes[1]=false;
        vector<int>lowest_prime(n+1,0);
      seive(n,primes,lowest_prime);
        // code here
     for(int i=0;i<=n+1;i++){
         if(lowest_prime[i]==0){
             lowest_prime[i]=i;
         }
     }
        return lowest_prime;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends