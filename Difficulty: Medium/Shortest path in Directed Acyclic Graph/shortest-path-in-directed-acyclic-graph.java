// User function Template for Java
class Solution {

    public int[] shortestPath(int V, int E, int[][] edges) {
        int[] shortestPaths = new int[V];
        ArrayList<int[]>[] adj = new ArrayList[V];
        
        for (int i = 0; i < V; i++) {
            shortestPaths[i] = -1;
            adj[i] = new ArrayList<int[]>();
        }
        
        // making the adjecency array for each node
        for (int i = 0; i < E; i++) {
            adj[edges[i][0]].add(new int[]{edges[i][1], edges[i][2]});
        }
        
        Queue<Integer> que = new LinkedList<>();
        que.add(0);
        shortestPaths[0] = 0;
        
        while (!que.isEmpty()) {
            int cur = que.poll();
            for (int[] nbr: adj[cur]) {
                int distance = shortestPaths[cur] + nbr[1];
                
                if (shortestPaths[nbr[0]] == -1 || shortestPaths[nbr[0]] > distance) {
                    shortestPaths[nbr[0]] = distance;
                    que.add(nbr[0]);
                }
            }
        }
        
        return shortestPaths;
    }
}