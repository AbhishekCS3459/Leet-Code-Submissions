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
  // Brute force approach
  int height(TreeNode*root){
    if(root==NULL)return 0;
    return max(height(root->left),height(root->right))+1;
  }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
      int left=diameterOfBinaryTree(root->left);
      int right=diameterOfBinaryTree(root->right);
      int combo=height(root->left)+height(root->right);
      return (max(max(left,right),combo));
    }
};