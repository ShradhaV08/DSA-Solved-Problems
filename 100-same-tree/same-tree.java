class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // If both nodes are null, trees are same here
        if (p == null && q == null) return true;

        // If one is null and the other is not, trees differ
        if (p == null || q == null) return false;
//DSA
        // If values are different, trees differ
        if (p.val != q.val) return false;

        // Recursively check left and right subtrees
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
