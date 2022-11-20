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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       // base condition
      if(p==NULL && q==NULL)return true;
      if(p==NULL && q!=NULL)return false;
      if(q==NULL && p!=NULL)return false;
      
      bool left_val=isSameTree(p->left,q->left);
      bool right_val=isSameTree(p->right,q->right);
      if(left_val && right_val && p->val==q->val)return true;
      else 
        return false;
      
    }
};