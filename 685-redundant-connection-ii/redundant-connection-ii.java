class Solution {

    public int[] findRedundantDirectedConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n + 1];

        // Step 1: detect node with two parents
        int[] candA = null;
        int[] candB = null;

        for (int i = 1; i <= n; i++) parent[i] = i;

        for (int[] e : edges) {
            int u = e[0], v = e[1];
            if (parent[v] != v) {
                // v has two parents
                candA = new int[]{parent[v], v};
                candB = new int[]{u, v};
                e[1] = 0; // invalidate second edge temporarily
            } else {
                parent[v] = u;
            }
        }

        // Step 2: Union-Find to detect cycle
        for (int i = 1; i <= n; i++) parent[i] = i;

        for (int[] e : edges) {
            if (e[1] == 0) continue;

            int u = e[0], v = e[1];
            int pu = find(parent, u);

            if (pu == v) {
                // cycle found
                return candA == null ? e : candA;
            }
            parent[v] = pu;
        }

        // No cycle, remove the second parent edge
        return candB;
    }

    private int find(int[] parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
}
//DSA