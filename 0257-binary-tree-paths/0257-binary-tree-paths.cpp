/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void operation(TreeNode*root,vector<string>&ans,string str){
    // base case
        if(root==NULL)
            return;
    // either root left !=NULL or right not equal to null we will insert arrow after the root val
        if(root->left!=NULL || root->right!=NULL ){
            str+=(to_string(root->val)+"->");
        }
    // else we will insert the root val
    else{
            ans.push_back(str+=(to_string(root->val)));
        }
        operation(root->left,ans,str);
        operation(root->right,ans,str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string str="";
        operation(root,ans,str);
        
        return ans;
    }
};