class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;

        // find length and tail
        ListNode tail = head;
        int len = 1;
        while (tail.next != null) {
            tail = tail.next;
            len++;
        }

        // make it circular
        tail.next = head;

        // effective rotations
        k = k % len;
        int stepsToNewHead = len - k;

        // find new tail
        ListNode newTail = tail;
        while (stepsToNewHead-- > 0) {
            newTail = newTail.next;
        }

        // break the circle
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}
//DSA