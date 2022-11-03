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
    vector<vector<int>>get_level_order_trav(TreeNode*root){
         vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>temp;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*t=q.front();
                q.pop();
                if(t->left!=NULL)q.push(t->left);
                 if(t->right!=NULL)q.push(t->right);
                temp.push_back(t->val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
   vector<double> ans;
 auto nodes=get_level_order_trav(root);
        for(auto in : nodes){
            for(auto k:in)cout<<k<<" ";
            cout<<endl;
        }
        
        
        for(int i=0;i<nodes.size();i++){
            double sum=0;
            for(int j=0;j<nodes[i].size();j++){
                sum+=nodes[i][j];
            }
            double average=sum/nodes[i].size();
            ans.push_back(average);
        }
        
        
        
        
        
        
        
        
        return ans;
    }
};