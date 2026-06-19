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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int length = 0;
        while(temp!=nullptr)
        {
            length++;
            temp = temp->next;
        }

        if(length==n)
        return head->next;

        int position = length - n -1;
        ListNode *prev = head;
        for(int i=0;i<position;i++)
        {
            prev = prev->next;
        }
        prev->next = prev->next->next;

        return head;
    }
};
