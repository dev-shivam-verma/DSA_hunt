class Solution {
    public int[] dijkstra(int V, int[][] edges, int src) {
        // code here
        int[] shortestDistances = new int[V];
        ArrayList<int[]>[] adjacencyList = new ArrayList[V];
        
        // initializations
        for (int i = 0; i < V; i++) {
            shortestDistances[i] = -1;
            adjacencyList[i] = new ArrayList<int[]>();
        }
        
        for (int[] edge: edges) {
            // because of undirected graph, 0 -> 1 also 1 -> 0
            adjacencyList[edge[0]].add(new int[]{edge[1], edge[2]});
            adjacencyList[edge[1]].add(new int[]{edge[0], edge[2]});
        }
        
        Queue<Integer> que = new LinkedList<>();
        shortestDistances[src] = 0;
        que.add(src);
        
        while (!que.isEmpty()) {
            int cur = que.poll();
            for (int[] nbr: adjacencyList[cur]) {
                if (shortestDistances[nbr[0]] == -1 || shortestDistances[nbr[0]] > shortestDistances[cur] + nbr[1]) {
                    shortestDistances[nbr[0]] = shortestDistances[cur] + nbr[1];
                    que.add(nbr[0]);
                }
            }
        }
        
        return shortestDistances;
    }
}