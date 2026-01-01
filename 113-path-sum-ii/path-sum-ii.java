import java.util.*;

class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> result = new ArrayList<>();
        dfs(root, targetSum, new ArrayList<>(), result);
        return result;
    }

    private void dfs(TreeNode node, int targetSum, List<Integer> path, List<List<Integer>> result) {
        if (node == null) return;

        path.add(node.val);
        targetSum -= node.val;

        // check if leaf node and sum matches
        if (node.left == null && node.right == null && targetSum == 0) {
            result.add(new ArrayList<>(path));
        }

        dfs(node.left, targetSum, path, result);
        dfs(node.right, targetSum, path, result);

        // backtrack
        path.remove(path.size() - 1);
    }
}
