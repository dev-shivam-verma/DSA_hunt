class Solution {
    public int countPaths(int n, int[][] roads) {
        int mod = 1_000_000_007;
        long[] shortestPaths = new long[n];
        int[] ways = new int[n];
        ArrayList<int[]>[] adj = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            shortestPaths[i] = Long.MAX_VALUE;
            adj[i] = new ArrayList<>();
            ways[i] = 0;
        }

        // Build graph
        for (int[] road : roads) {
            adj[road[0]].add(new int[]{road[1], road[2]});
            adj[road[1]].add(new int[]{road[0], road[2]});
        }

        PriorityQueue<long[]> pq = new PriorityQueue<>(
            (a, b) -> Long.compare(a[1], b[1])
        );

        shortestPaths[0] = 0;
        ways[0] = 1;
        pq.add(new long[]{0, 0}); 

        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            int intersection = (int) cur[0];
            long time = cur[1];

            for (int[] nbr : adj[intersection]) {
                int neighbor = nbr[0];       
                long newTime = time + nbr[1];

                if (newTime < shortestPaths[neighbor]) {
                    shortestPaths[neighbor] = newTime;
                    pq.add(new long[]{neighbor, newTime});
                    ways[neighbor] = ways[intersection];
                } else if (newTime == shortestPaths[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[intersection]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
}
