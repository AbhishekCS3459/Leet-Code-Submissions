//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


// } Driver Code Ends
//User function Template for C++
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

class Solution {
  public:
  vector<vector<int>>level_order(Node* node){
      queue<Node*>q;
      q.push(node);
       vector<vector<int>>ans;
      while(!q.empty()){
          int k = q.size();
                  vector<int>temp;
          for(int i=0;i<k;i++){
              Node*rt= q.front();q.pop();
              if(rt->left)q.push(rt->left);
              if(rt->right)q.push(rt->right);
              temp.push_back(rt->data);
          }
          ans.push_back(temp);
      }
      return ans;
  }
  
    vector<int> maximumValue(Node* node) {
        vector<int>ans;
        if(!node)return ans;
        auto levels = level_order(node);
        for(auto in:levels){
            int mx=INT_MIN;
            for(auto ele:in){
                // cout<<ele<<" ";
                mx=max(mx,ele);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};

//{ Driver Code Starts.

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
/* Function to get Largest value at each level of Binary Tree */
vector<int> maximumValue(struct Node* tree);


int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> answer = ob.maximumValue(root);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends