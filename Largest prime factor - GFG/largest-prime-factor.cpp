//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 

long long seive_lowest_highest(int n,vector<bool>&is_prime)
{
    vector<long long>highest_prime(n+1,0);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] == 1)
        {
            highest_prime[i] = i;
            for (int j = 2 * i; j <= n; j += i)
            {
                is_prime[j] = 0;

                highest_prime[j] = i;
            }
        }
    }
    return highest_prime[n];
}
    long long int largestPrimeFactor(int N){
        // code here
        // write the seive and find the largetst prime
        vector<bool>is_prime(N+1,true);
       return seive_lowest_highest(N,is_prime);
       
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends