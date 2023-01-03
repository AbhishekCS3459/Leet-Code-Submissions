//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  map<Node*,Node*>m;
  map<Node*,bool>vis;
  Node*target_nd;
  void make_connections_parents(Node*root,int target){
      if(!root)return;
      if(target==root->data)target_nd=root;
      if(root->left)m[root->left]=root;
      if(root->right)m[root->right]=root;
      make_connections_parents(root->left,target);
      make_connections_parents(root->right,target);
  }
    int minTime(Node* root, int target) 
    {
        // make the connections with parents
        make_connections_parents(root,target);
        queue<Node*>q;
        vector<vector<int>>ans;
        q.push(target_nd);
        
        while(!q.empty()){
            int k =q.size();
            vector<int>temp;
            for(int i=0;i<k;i++){
                Node*rt=q.front();
                q.pop();
                if(rt->left && !vis[rt->left]){
                    q.push(rt->left);
                    vis[rt->left]=true;
                }
                if(rt->right && !vis[rt->right]){
                    q.push(rt->right);
                    vis[rt->right]=true;
                }
                if(m[rt]&& !vis[m[rt]])
                {
                       q.push(m[rt]);
                    vis[m[rt]]=true;
                }
                temp.push_back(rt->data);
            }
            ans.push_back(temp);
        }
        
        // for(auto in:ans){
        //     for(auto ele:in)
        //     cout<<ele<<" ";
        //     cout<<endl;
        // }
        return ans.size()-1;
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends