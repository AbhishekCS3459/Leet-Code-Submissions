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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL)return NULL;
    
        ListNode*s=head;
        ListNode*pre=NULL,*f=head->next;
        while(f!=NULL ){
         f=f->next;
            if(f!=NULL)f=f->next;
            pre=s;
            s=s->next;
        
        }
        ListNode*del=s;
        s=s->next;
        pre->next=s;
        delete(del);
        return head;
        
    }
};