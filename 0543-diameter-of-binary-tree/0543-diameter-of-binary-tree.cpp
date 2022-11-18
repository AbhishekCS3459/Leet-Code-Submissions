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
  // Love Bababar
   pair<int,int>Optimised_function_for_diameter(TreeNode*root){
          if(root==NULL)return {0,0};
            pair<int,int> left=Optimised_function_for_diameter(root->left);
            pair<int,int> right=Optimised_function_for_diameter(root->right);
        
        int op1=left.first;
        int op2=right.first;
        int combo=left.second+right.second;
        
        
        int diameter=max(max(op1,op2), combo);
        int max_height=1+max(left.second,right.second);
        return {diameter,max_height};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return Optimised_function_for_diameter(root).first;
    }
};