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
    ListNode *Reverse(ListNode *curr,ListNode *prev)
    {
        if(curr == nullptr)
        return prev;
        ListNode *next = curr->next;
        curr->next = prev;
        return Reverse(next,curr);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode *first = l1,*second = l2;
        // first = Reverse(first,nullptr);
        // second = Reverse(second,nullptr);
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;
        ListNode *head = new ListNode(0);
        int carry = 0,sum;
        ListNode *tail = head;

        while(curr1 && curr2)
        {
            sum = curr1->val + curr2->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
            carry = sum/10;
        }
        while(curr1)
        {
            sum = curr1->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            curr1 = curr1->next;
            carry = sum/10;
        }
        while(curr2)
        {
            sum = curr2->val + carry;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            curr2 = curr2->next;
            carry = sum/10;
        }
        while(carry)
        {
            tail->next = new ListNode(carry%10);
            tail = tail->next;
            carry = carry/10;
        }
        // head = Reverse(head->next,nullptr);
        return head->next;
    }
};
