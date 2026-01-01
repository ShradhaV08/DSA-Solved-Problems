class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode prev = dummy;
        ListNode curr = head;

        while (curr != null) {
            // check if current value has duplicates
            if (curr.next != null && curr.val == curr.next.val) {
                int dupVal = curr.val;
                // skip all nodes with this value
                while (curr != null && curr.val == dupVal) {
                    curr = curr.next;
                }
                prev.next = curr;
            } else {
                prev = curr;
                curr = curr.next;
            }
        }

        return dummy.next;
    }
}
