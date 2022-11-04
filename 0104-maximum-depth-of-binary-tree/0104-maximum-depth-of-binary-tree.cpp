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
   vector<vector<int>>ans;
    void level_wise_traversal(TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>v;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*t=q.front();
                q.pop();
                if(t->left!=NULL)q.push(t->left);
                    if(t->right!=NULL)q.push(t->right);
                v.push_back(t->val);
            }
            ans.push_back(v);
        }
    
    }
    int maxDepth(TreeNode* root) {
        // Using DFS
        
        if(root==NULL)return 0;
        level_wise_traversal(root);
        for(auto in : ans){
            for(auto ele:in)cout<<ele<<" ";
            cout<<endl;
        }
        return ans.size();
    }

};