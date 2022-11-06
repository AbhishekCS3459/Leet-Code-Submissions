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
    // O{n^2} solution
    
//     int height(TreeNode* root){
//         if(root==NULL)return 0;
//         return 1+max( height(root->left), height(root->right) );
//     }
//     bool isBalanced(TreeNode* root) {
//         if(root==NULL)return true;
//        if(abs( height(root->left) - height(root->right) )>1 ) // checking height from the root node
//            return false;
        
//         // now checking height from further node.
//        if(!isBalanced(root->left) || !isBalanced(root->right)  )return false;
//         return true;    
//     }
    
    // Modifyed height function
        int modified_height(TreeNode* root){
        if(root==NULL)return 0;
            
           int lh=modified_height(root->left);
            if(lh==-1)return -1;
            
       int rh= modified_height(root->right);
            if(rh==-1)return -1;
            
    if(abs(rh-lh)>1)return -1;
    return 1+max( lh,rh);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
if (modified_height(root)==-1)return false;
        else
            return true;
    }
};