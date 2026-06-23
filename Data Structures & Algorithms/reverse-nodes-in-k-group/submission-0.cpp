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
  ListNode * kthele(ListNode* head,int k){
    k--;
    while(head!=NULL&&k>0){
        k--;
        head=head->next;
    }
    return head;
  }
   ListNode * reveselist(ListNode* head){
     ListNode* cur=head;
     ListNode  * prev=NULL;
     while(cur!=NULL){
          ListNode* next=cur->next;
          cur->next=prev;
          prev=cur;
          cur=next;
     }
     return prev;
   }
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode * prevnode=NULL;
       ListNode * nextnode=NULL;
       ListNode *temp=head;
       while(temp!=NULL){
          ListNode * kth=kthele(temp,k);
          if(kth==NULL){
            if(prevnode)prevnode->next=temp;
            break;
          }
          nextnode=kth->next;
          kth->next=NULL;
          reveselist(temp);
          if(head==temp){
            head=kth;
          }
          else{
            prevnode->next=kth;
          }
          prevnode=temp;
          temp=nextnode;
       }
       return head;
        
    }
};
