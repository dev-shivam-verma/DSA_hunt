class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        int[] r_time = new int[n + 1];
        ArrayList<int[]>[] adj = new ArrayList[n + 1];

        for (int i = 0; i <= n; i++) {
            r_time[i] = Integer.MAX_VALUE;
            adj[i] = new ArrayList<int[]>();
        }

        for (int[] time: times) {
            adj[time[0]].add(new int[] {time[1], time[2]});
        }

        PriorityQueue<int[]> que = new PriorityQueue<>(
            (a,b) -> a[1] - b[1]
        );

        que.add(new int[] {k, 0});
        r_time[k] = 0;

        while (!que.isEmpty()) {
            int[] cur = que.poll();
            int node = cur[0];
            int curTime = cur[1];

            for (int[] nbr: adj[node]) {
                int time = curTime + nbr[1];

                if (r_time[nbr[0]] > time) {
                    r_time[nbr[0]] = time;
                    que.add(new int[] {nbr[0], time});
                }
            }
        }

        
        int minTime = 0;
        for (int x = 1; x <= n; x++) {
            int i = r_time[x];
            if (i == Integer.MAX_VALUE) return -1;
            minTime = Math.max(minTime, i);
        }

        return minTime;
    }
}