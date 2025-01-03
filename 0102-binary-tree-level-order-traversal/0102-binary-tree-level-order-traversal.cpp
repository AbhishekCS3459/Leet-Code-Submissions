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
    vector<vector<int>> levelOrder(TreeNode* root) {
      
          vector<vector<int>>ans;
          if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int k  = q.size();
            for(int i =0;i<k;i++){
                   TreeNode*t=q.front();
                if(t->left!=NULL)q.push(t->left);
                if(t->right!=NULL)q.push(t->right);
             
                q.pop();
                temp.push_back(t->val);
            }
            ans.push_back(temp);
        }
        
        
        return ans;
    }
};