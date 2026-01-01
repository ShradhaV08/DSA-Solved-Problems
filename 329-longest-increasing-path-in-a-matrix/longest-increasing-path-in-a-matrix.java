class Solution {
    private int m, n;
    private int[][] memo;
    private int[][] dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0) return 0;

        m = matrix.length;
        n = matrix[0].length;
        memo = new int[m][n];

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = Math.max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }

    private int dfs(int[][] matrix, int r, int c) {
        if (memo[r][c] != 0) return memo[r][c];

        int max = 1;
        for (int[] d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                matrix[nr][nc] > matrix[r][c]) {
                max = Math.max(max, 1 + dfs(matrix, nr, nc));
            }
        }

        memo[r][c] = max;
        return max;
    }
}
//DSA