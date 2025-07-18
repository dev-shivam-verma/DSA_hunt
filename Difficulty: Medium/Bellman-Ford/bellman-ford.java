// User function Template for Java

class Solution {
    public int[] bellmanFord(int V, int[][] edges, int src) {
        // code here
        int[] sp = new int[V];
        
        // initialization 
        for (int i = 0; i < V; i++) {
            sp[i] = 1_00_000_000;
        }
        
        sp[src] = 0;
        
        for (int n = 1; n < V; n++) {
            for (int[] edge: edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if (sp[u] != 1_00_000_000 && sp[u] + wt < sp[v]) {
                    sp[v] = sp[u] + wt;
                }
            }
        }
        
        
        // checking Nth time for cycle detection 
        for (int[] edge: edges) {
            int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if (sp[u] != 1_00_000_000 && sp[u] + wt < sp[v]) {
                    return new int[]{-1};
                }
        }
        
        return sp;
    }
}
