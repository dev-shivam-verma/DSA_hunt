class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[] reachable = new int[n];

        int[][] adj = new int[n][n];

        // initialization 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = Integer.MAX_VALUE;
            }
        }

        for (int[] edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt= edge[2];

            adj[u][v] = wt;
            adj[v][u] = wt;
        }




        for (int x = 0; x < n; x++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][x] != Integer.MAX_VALUE && adj[x][j] != Integer.MAX_VALUE && adj[i][x] + adj[x][j] < adj[i][j]) {
                        adj[i][j] = adj[i][x] + adj[x][j];
                    }
                }
            }
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && adj[i][j] <= distanceThreshold) reachable[i]++;
            }
        }
        
        int result = 0;
        int cities = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (reachable[i] < cities) {
                cities = reachable[i];
                result = i;
            } else if (reachable[i] == cities) {
                result = Math.max(cities, i);
            }
        }

        return result;
    }
}