//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
// This class defines a node with a value and an index.
class Node {
public:
    int value; // The value of the node.
    int index; // The index of the node in the original array.

    // Constructor that initializes the value and index of the node.
    Node(int value, int index) {
        this->value = value;
        this->index = index;
    }
};

// This class defines a comparator function for Node objects.
class NodeComparator {
public:
    bool operator()(Node* a, Node* b) {
        // Compares the values of the two Node objects.
        return a->value > b->value;
    }
};

// This function takes an array of integers and replaces each element with its rank (1-based).
vector<int> replaceWithRank(vector<int>& arr, int N) {
    // Creates a priority queue of Node pointers using the custom comparator.
    priority_queue<Node*, vector<Node*>, NodeComparator> pq;

    // Adds all elements of the input array to the priority queue as Nodes.
    for (int i = 0; i < N; i++) {
        pq.push(new Node(arr[i], i));
    }

    // Repeatedly pops the smallest Node from the priority queue and replaces its corresponding element in the array with its rank.
    int rank = 0;
    int prevValue = INT_MIN;
    while (!pq.empty()) {
        Node* current = pq.top();
        pq.pop();
        rank++;
        if (prevValue == current->value) {
            rank--;
        }
        prevValue = current->value;
        int index = current->index;
        arr[index] = rank;
    }

    // Returns the modified array.
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