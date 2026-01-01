import java.util.*;

class TextEditor {
    private StringBuilder left;   // text to the left of cursor
    private StringBuilder right;  // text to the right of cursor

    public TextEditor() {
        left = new StringBuilder();
        right = new StringBuilder();
    }

    // Add text at cursor
    public void addText(String text) {
        left.append(text);
    }

    // Delete k characters to the left of cursor
    public int deleteText(int k) {
        int deleteCount = Math.min(k, left.length());
        left.delete(left.length() - deleteCount, left.length());
        return deleteCount;
    }

    // Move cursor left k times
    public String cursorLeft(int k) {
        int move = Math.min(k, left.length());
        for (int i = 0; i < move; i++) {
            right.append(left.charAt(left.length() - 1));
            left.deleteCharAt(left.length() - 1);
        }
        return getLast10();
    }

    // Move cursor right k times
    public String cursorRight(int k) {
        int move = Math.min(k, right.length());
        for (int i = 0; i < move; i++) {
            left.append(right.charAt(right.length() - 1));
            right.deleteCharAt(right.length() - 1);
        }
        return getLast10();
    }

    // Helper: last min(10, len) characters to the left of cursor
    private String getLast10() {
        int len = left.length();
        return left.substring(Math.max(0, len - 10), len);
    }
}
