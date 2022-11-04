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
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>st;
        TreeNode*nd=root;
        while(true){
            if(nd!=NULL){
                st.push(nd);
                nd=nd->left;
            }
            else{
                // condition for loop to stop
                if(st.empty())break;
                
                // backtrack
                nd=st.top();
                ans.push_back(nd->val);
                st.pop();
                // now call for the right
                nd=nd->right;   
            }         
        }
        return ans;
    }
};