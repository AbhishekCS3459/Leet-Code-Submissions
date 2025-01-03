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
    int height(TreeNode*root){
        if(root==NULL)return 0;
        
         int left=height(root->left);
        if(left==-1)return -1;
        
        int right=height(root->right);
        if(right==-1)return -1;
        
        if(abs(left-right)>1)return -1;
        
        return 1+max(height(root->left),height(root->right));
        
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        if(height(root)==-1)return false;
        else
            return true;
    }
};