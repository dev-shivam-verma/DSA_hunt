class Solution {
    private List<List<Integer>> ctlCon;
    private int[][] vis;
    private ArrayList<Integer>[] adj;
    private int time;

    private void dfs(int node, int parent) {
        vis[node][0] = time;
        vis[node][1] = time;
        time++;

        for (int nbr: adj[node]) {
            if (nbr == parent) continue;

            if (vis[nbr][0] == -1) {
                dfs(nbr, node);

                if (vis[nbr][1] > vis[node][0]) {
                   ctlCon.add(List.of(node, nbr));
                }

            } 
            vis[node][1] = Math.min(vis[node][1], vis[nbr][1]);
        }
    }


    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        ctlCon = new ArrayList<>();
        time = 1;

        vis = new int[n][2];
        adj = new ArrayList[n];

        for (int i = 0; i < n; i++) {
            vis[i][0] = -1;
            adj[i] = new ArrayList<Integer>();
        }

        // filling up adjacency list
        for (List<Integer> connection: connections) {
            adj[connection.get(0)].add(connection.get(1));
            adj[connection.get(1)].add(connection.get(0));
        }

        dfs(0, -1);

        return ctlCon;
    }
}