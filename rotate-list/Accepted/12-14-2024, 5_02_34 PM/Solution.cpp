// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode* temp = head;
        int len=1, i=1;
        while(temp->next != NULL) {
            len++;
            temp = temp->next;
        }
        temp->next = head;
        temp = head;
        while(i < (len - (k % len))) {
            temp = temp->next;
            i++;
        }
        ListNode* newhead = temp->next;
        temp->next = NULL;
        return newhead;
    }
};