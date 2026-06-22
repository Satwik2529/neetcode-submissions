class Solution {
public:
    int sizeoflist(ListNode * head){
        int len=0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }

    ListNode * reverse(ListNode* head){
        ListNode * cur=head;
        ListNode* prev=NULL;

        while(cur!=NULL){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {

        if(head==NULL || head->next==NULL) return;

        ListNode* temp=head;
        double hi=sizeoflist(head);
        hi=ceil(hi/2);

        int count=0;
        ListNode* prev=NULL;

        while(count!=hi){
            prev=temp;
            temp=temp->next;
            count++;
        }

        prev->next=NULL;     

        ListNode* newhead=reverse(temp);

        while(head!=NULL && newhead!=NULL){

            ListNode* first=head->next;
            ListNode* second=newhead->next;

            head->next=newhead;

            if(first==NULL) break;

            newhead->next=first;

            head=first;
            newhead=second;
        }
    }
};