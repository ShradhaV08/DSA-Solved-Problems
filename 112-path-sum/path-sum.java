class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) return false;

        // If it's a leaf node, check if remaining sum equals node value
        if (root.left == null && root.right == null) {
            return targetSum == root.val;
        }

        // Recurse on left and right subtrees
        return hasPathSum(root.left, targetSum - root.val) ||
               hasPathSum(root.right, targetSum - root.val);
    }
}
