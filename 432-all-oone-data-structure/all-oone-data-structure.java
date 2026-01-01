import java.util.*;

class AllOne {

    private static class Node {
        int count;
        Set<String> keys;
        Node prev, next;

        Node(int count) {
            this.count = count;
            this.keys = new HashSet<>();
        }
    }

    private Node head, tail;
    private Map<String, Node> keyToNode;

    public AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head.next = tail;
        tail.prev = head;
        keyToNode = new HashMap<>();
    }

    public void inc(String key) {
        if (!keyToNode.containsKey(key)) {
            Node node = head.next;
            if (node == tail || node.count != 1) {
                node = insertAfter(head, new Node(1));
            }
            node.keys.add(key);
            keyToNode.put(key, node);
        } else {
            Node curr = keyToNode.get(key);
            Node next = curr.next;
            int newCount = curr.count + 1;

            if (next == tail || next.count != newCount) {
                next = insertAfter(curr, new Node(newCount));
            }

            next.keys.add(key);
            keyToNode.put(key, next);

            curr.keys.remove(key);
            if (curr.keys.isEmpty()) remove(curr);
        }
    }

    public void dec(String key) {
        Node curr = keyToNode.get(key);

        if (curr.count == 1) {
            curr.keys.remove(key);
            keyToNode.remove(key);
            if (curr.keys.isEmpty()) remove(curr);
        } else {
            Node prev = curr.prev;
            int newCount = curr.count - 1;

            if (prev == head || prev.count != newCount) {
                prev = insertAfter(curr.prev, new Node(newCount));
            }

            prev.keys.add(key);
            keyToNode.put(key, prev);

            curr.keys.remove(key);
            if (curr.keys.isEmpty()) remove(curr);
        }
    }

    public String getMaxKey() {
        if (tail.prev == head) return "";
        return tail.prev.keys.iterator().next();
    }

    public String getMinKey() {
        if (head.next == tail) return "";
        return head.next.keys.iterator().next();
    }

    private Node insertAfter(Node prev, Node node) {
        node.next = prev.next;
        node.prev = prev;
        prev.next.prev = node;
        prev.next = node;
        return node;
    }

    private void remove(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
}
