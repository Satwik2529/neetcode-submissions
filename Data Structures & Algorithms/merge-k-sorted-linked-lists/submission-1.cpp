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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* copy = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                dummy->next = l1;
                dummy = dummy->next;
                l1 = l1->next;
            } else {
                dummy->next = l2;
                dummy = dummy->next;
                l2 = l2->next;
            }
        }
        while (l1) {
            dummy->next = l1;
            dummy = dummy->next;
            l1 = l1->next;
        }
        while (l2) {
            dummy->next = l2;
            dummy = dummy->next;
            l2 = l2->next;
        }

        return copy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        for (int i = 1; i < lists.size(); i++) {
            lists[i] = merge(lists[i], lists[i - 1]);
        }

        return lists.back();
    }
};
