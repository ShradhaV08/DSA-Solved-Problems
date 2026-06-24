struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;

    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next)
        return head;

    // Find middle
    struct ListNode *slow = head, *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *mid = slow->next;
    slow->next = NULL;

    // Sort both halves
    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(mid);

    // Merge
    return merge(left, right);
}