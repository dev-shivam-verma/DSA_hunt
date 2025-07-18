// User function template for JAVA

class Solution {
    public void floydWarshall(int[][] dist) {
        // Code here
        int n = dist.length;
        int infinity = 1_00_000_000;
        
        for (int x = 0; x < n; x++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][x] != infinity && dist[x][j] != infinity && dist[i][x] + dist[x][j] < dist[i][j]) {
                        dist[i][j] = dist[i][x] + dist[x][j];
                    }
                }
            }
        }
        
        
    }
}