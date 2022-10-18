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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        ListNode*t1=l1,*t2=l2;
        while(t1!=NULL || t2!=NULL ||c!=0){
            int a=0;
            if(t1!=NULL){
                a=t1->val;
            }
            int b=0;
            if(t2!=NULL){
                b=t2->val;
            }
            
            int sum=a+b+c;
            int digit=sum%10;
           temp->next=new ListNode(digit);
            temp=temp->next;
         if(t1!=NULL)
             t1=t1->next;
            if(t2!=NULL)
                t2=t2->next;
       c=sum/10;
            
        }
return dummy->next;
    }
};