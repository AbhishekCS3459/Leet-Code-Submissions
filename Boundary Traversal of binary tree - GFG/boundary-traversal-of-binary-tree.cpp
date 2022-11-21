//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
 vector <int> ans;

void traverse_left(Node*root){
    if(root==NULL ||root->left==NULL && root->right==NULL )return;
    ans.push_back(root->data);
    if(root->left)
    traverse_left(root->left);
    else
    traverse_left(root->right); 
}
    void inorder_traversal(Node*root){
        if(root==NULL){
            return;
        }
        
        inorder_traversal(root->left);
        if(root->left==NULL && root->right==NULL)
        ans.push_back(root->data);
        inorder_traversal(root->right);
    }
    
    vector <int> boundary(Node *root)
    {
        if(root==NULL)return ans;
        //first get left excluding the left part
        ans.push_back(root->data);
        traverse_left(root->left);
        // for left subtree
        inorder_traversal(root->left);
        inorder_traversal(root->right);
        // traverse the right part
        traverse_right(root->right);
   
        return ans;
        
    }
    
void traverse_right(Node*root){
    if(root==NULL)return;
        if(root==NULL ||root->left==NULL && root->right==NULL )return;

    if(root->right){
    traverse_right(root->right); 
    }
    else
    traverse_right(root->left);
    ans.push_back(root->data);
    
}
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends