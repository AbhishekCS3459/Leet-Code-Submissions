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
  // int height(TreeNode*root){
  //   if(root==NULL)return 0;
  //   else
  //     return max(height(root->left),height(root->right))+1;
  // }
  pair<int,int>Optimised_func(TreeNode*root){
    if(root==NULL)return {0,0};
    pair<int,int>left=Optimised_func(root->left);
    pair<int,int>right=Optimised_func(root->right);
   int d_l=left.first;
    int d_r=right.first;
    int combo=left.second+right.second;
    
    
    int diameter=max(max(d_l,d_r),combo);
    int height=max(left.second,right.second)+1;
    return {diameter,height};
  }
  
    int diameterOfBinaryTree(TreeNode* root) {
       return Optimised_func(root).first;
      
    }
};