/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
      vector<int> nextLargerNodes(ListNode* head) {
       
            vector<int> ans,data;
         if(head==NULL)return ans;
       // head= reverse_linked(head);
        
        // getting data into data vector
        while(head){
            int x=head->val;
            data.push_back(x);
            head=head->next;
        }
        
        
        stack<int>s;
        for(int i=data.size()-1;i>=0;i--){
            if(s.empty())ans.push_back(0);
            else if(!s.empty()&&s.top()>data[i]){
                ans.push_back(s.top());
            }
            else if(!s.empty()&& s.top()<=data[i]){
                while(!s.empty()&&s.top()<=data[i])s.pop();
                if(s.empty())ans.push_back(0);
                else
                    ans.push_back(s.top());
            }
            s.push(data[i]);
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
    ListNode* removeNodes(ListNode* head) {
    if(head==NULL || head->next==NULL)return head;

      auto ans=nextLargerNodes(head);
      ListNode*curr=head;
      int i=0;
      ListNode*dummy=new ListNode(-1);
      
      dummy->next=head;
      
      ListNode*pre=NULL,*temp=dummy;
      while(i<ans.size()){
       if(ans[i]==0){
         ListNode*new_node=new ListNode(curr->val);
         temp->next=new_node;
         temp=new_node;
       }
        curr=curr->next;
        i++;
      }
      return dummy->next;
    }
};