class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[][] visited = new int[n][2];

        for (int i = 0; i < n; i++) {
            if (visited[i][0] == 0) {
                visited[i] = new int[]{1, 0};
                Queue<Integer> que = new LinkedList<>();

                que.add(i);
                while (!que.isEmpty()) {
                    int cur = que.poll();

                    int nbrSet = visited[cur][1] == 0? 1: 0;
                    for (int nbr: graph[cur]) {
                        if (visited[nbr][0] == 1) {
                            if (visited[nbr][1] != nbrSet) return false;
                        } else {
                            visited[nbr][0] = 1;
                            visited[nbr][1] = nbrSet;

                            que.add(nbr);
                        }
                    }
                    
                } 
            }
        }

        return true;
    }
}