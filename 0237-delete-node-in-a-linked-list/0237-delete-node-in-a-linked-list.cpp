/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
 
        ListNode*pre=NULL;
        ListNode*curr=node;
        ListNode*nex=node->next;
        
        while(nex){
        std::swap(curr->val,nex->val);
            pre=curr;
            curr=nex;
            nex=nex->next;
            
        }
        // now curr is at the node which has to be deleted and it is the last positon
         cout<<pre->val<<" "<<curr->val;
        pre->next=NULL;
        
        
    }
};