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

  pair<int,int> Max_path_sum(TreeNode*root,int &mx){
    if(root==NULL)return {0,0};
    int left_sum=Max_path_sum(root->left,mx).first;
    int right_sum=Max_path_sum(root->right,mx).first;
    
    if(left_sum<0)left_sum=0;
    
    if(right_sum<0)right_sum=0;
    
    mx=max(mx,left_sum+right_sum+root->val);
    
    return {root->val+max(left_sum,right_sum),mx};
    
  }
    int maxPathSum(TreeNode* root) {
      int mx=INT_MIN;
        return Max_path_sum(root,mx).second;
    }
};