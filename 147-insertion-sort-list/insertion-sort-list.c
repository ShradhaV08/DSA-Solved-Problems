/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = NULL;

    while (head) {
        struct ListNode *curr = head;
        head = head->next;

        struct ListNode *prev = &dummy;

        while (prev->next && prev->next->val < curr->val)
            prev = prev->next;

        curr->next = prev->next;
        prev->next = curr;
    }

    return dummy.next;
}