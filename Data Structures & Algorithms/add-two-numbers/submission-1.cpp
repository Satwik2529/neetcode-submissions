class Solution {
public:
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {

        ListNode* dummy = new ListNode(0);
        ListNode* copy = dummy;

        bool carry = false;

        while (head1 != NULL || head2 != NULL) {

            int val = 0;

            if (head1 != NULL) {
                val += head1->val;
            }

            if (head2 != NULL) {
                val += head2->val;
            }

            if (carry) val += 1;

            if (val >= 10) {
                carry = true;
                val %= 10;
            } else {
                carry = false;
            }

            ListNode* value = new ListNode(val);
            dummy->next = value;
            dummy = dummy->next;

            if (head1 != NULL) head1 = head1->next;
            if (head2 != NULL) head2 = head2->next;
        }

        if (carry) {
            dummy->next = new ListNode(1);
        }

        return copy->next;
    }
};