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
    int len(ListNode *head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = len(head);

        if (l <= 1) return NULL;

        int k = l - n;

        if (k == 0) return head->next;

        ListNode* start = head;
        int count = 1;

        while (count != k) {
            start = start->next;
            count++;
        }

        start->next = start->next->next;

        return head;
    }
};