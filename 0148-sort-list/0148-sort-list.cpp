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
  ListNode *merge(ListNode *&left, ListNode *right)
{
    ListNode *l1 = left, *r1 = right;
    if (l1 == NULL)
        return r1;
    if (r1 == NULL)
        return l1;
    ListNode *dummy = new ListNode(-1), *temp = dummy;
    while (l1 && r1)
    {
        if (l1->val < r1->val)
        {
            temp->next = new ListNode(l1->val);
            temp = temp->next;
            l1 = l1->next;
        }
        else
        {
            temp->next = new ListNode(r1->val);
            temp = temp->next;
            r1 = r1->next;
        }
    }
    while (l1)
    {
        temp->next = new ListNode(l1->val);
        temp = temp->next;
        l1 = l1->next;
    }
    while (r1)
    {
        temp->next = new ListNode(r1->val);
        temp = temp->next;
        r1 = r1->next;
    }
    return dummy->next;
}
public:
  ListNode *get_mid(ListNode *&head)
{
    ListNode *fast = head->next;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
  ListNode*merge_sort(ListNode*head){
    if(head==NULL || head->next==NULL)return head;
    ListNode*mid=get_mid(head);
    ListNode*h1=head;
    ListNode*h2=mid->next;
    mid->next=NULL;
    ListNode*l1=merge_sort(h1);
  ListNode*l2 = merge_sort(h2);
  return merge(l1,l2);
  }
    ListNode* sortList(ListNode* head) {
        if(head==NULL)return head;
      return merge_sort(head);
    }
};