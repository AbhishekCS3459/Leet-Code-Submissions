//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V,0);
	    for(auto i=0;i<V;i++){
	        for(auto in:adj[i]){
	            indegree[in]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int t=q.front();
	        q.pop();
	        for(auto in:adj[t]){
	            indegree[in]--;
	            if(indegree[in]==0)q.push(in);
	        }
	        ans.push_back(t);
	    }
	    return ans;
	}
    string findOrder(string dict[], int N, int K) {
        //first make the adj list for the charracters
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            // taking the first string and second as pair
            string s1=dict[i];
            string s2=dict[i+1];
            // now compare them based on their charracters order
            int min_leng=min(s1.length(),s2.length());
            for(int j=0;j<min_leng;j++){
                // here check if first string charracter 
                // comes first then make the directed edge form first to second
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }            
                
            }
        }
        // here we had made the adj list so 
        auto linear_ordering=topoSort(K,adj);
        // node we have the linear ordering means the order of which charraccter comes first
        string ans="";
        for(auto in:linear_ordering){
            ans+=char(in+'a');
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends