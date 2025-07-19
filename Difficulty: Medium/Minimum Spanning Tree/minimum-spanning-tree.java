class Solution {
    static int spanningTree(int V, int E, List<List<int[]>> adj) {
   
        int[] visited = new int[V];
        int sum = 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a,b) -> a[0] - b[0]    
        );
        
        pq.add(new int[] {0,0});
        
        while (!pq.isEmpty()) {
            int[] data = pq.poll();
            int wt = data[0];
            int node = data[1];
            
            if (visited[node] == 1) continue;
            visited[node] = 1; 
            sum += wt;
            
            
            for (int[] edge: adj.get(node)) {
                int cWt = edge[1];
                int child = edge[0];
                
                if (visited[child] != 1) {
                    pq.add(new int[] {cWt, child});
                }
            }
        }
        
        return sum;
    }
}