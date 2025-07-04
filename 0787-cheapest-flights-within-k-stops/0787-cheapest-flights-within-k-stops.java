class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[] prices = new int[n];
        ArrayList<int[]>[] adj = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            prices[i] = Integer.MAX_VALUE;
            adj[i] = new ArrayList<int[]>();
        }

        for (int[] flight: flights) {
            adj[flight[0]].add(new int[] {flight[1], flight[2]});
        }

        PriorityQueue<int[]> que = new PriorityQueue<>((a,b) -> {
            if (a[2] == b[2]) return a[1] - b[1];
            return a[2] - b[2];
        });
        que.add(new int[] {src, 0, 0});
        prices[src] = 0;

        while (!que.isEmpty()) {
            int[] cur = que.poll();
            if (cur[0] == dst || cur[2] > k) continue;

            for (int[] nbr: adj[cur[0]]) {
                int price = cur[1] + nbr[1];

                if (price < prices[nbr[0]]) {
                    prices[nbr[0]] = price;
                    que.add(new int[] {nbr[0], price, cur[2] + 1});
                }
            }
        }


        return prices[dst] == Integer.MAX_VALUE? -1: prices[dst];
    }
}