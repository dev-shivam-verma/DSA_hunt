class Solution {
    public int[] processQueries(int c, int[][] connections, int[][] queries) {
        int[] gridInfo = new int[c + 1];
        Map<Integer, TreeSet<Integer>> grids = new HashMap<>();
        ArrayList<Integer>[] adj = new ArrayList[c + 1];

        // initializing adjacency list
        for (int i = 1; i <= c; i++) {
            adj[i] = new ArrayList<Integer>();
        }

        // building adjacency list
        for (int[] connection: connections) {
            // bidirectional connection 
            adj[connection[0]].add(connection[1]);
            adj[connection[1]].add(connection[0]);
        }

        
        int gridsFound = 0;
        for (int i = 1; i <= c; i++) {
            if (gridInfo[i] == 0) {
                gridsFound++;
                gridInfo[i] = gridsFound;

                
                grids.put(gridsFound, new TreeSet<Integer>());
                grids.get(gridsFound).add(i);

                Queue<Integer> que = new LinkedList<>();
                que.add(i);

                while (!que.isEmpty()) {
                    int cur = que.poll();
                    for (int nbr: adj[cur]) {
                        if (gridInfo[nbr] == 0) {
                            gridInfo[nbr] = gridsFound;
                            grids.get(gridsFound).add(nbr);
    
                            que.add(nbr);
                        }
                    }
                }
            }
        }

        List<Integer> results = new ArrayList<>();
        for (int[] query: queries) {
            int st = query[1];
            TreeSet<Integer> stations = grids.get(gridInfo[st]);
            
            if (query[0] == 2) {
                stations.remove(st);                
            } 

            if (query[0] == 1) {
                if (stations.contains(st)) {
                    results.add(st);
                } else if (!stations.isEmpty()) {
                    results.add(stations.first());
                } else {
                    results.add(-1);
                }
            }
        }
        
        return results.stream().mapToInt(Integer::intValue).toArray();
    }
}