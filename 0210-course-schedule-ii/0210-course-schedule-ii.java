class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] indeg = new int[numCourses];
        List<Integer> ans = new ArrayList<>();
        Queue<Integer> que = new LinkedList<>(); 
        ArrayList<Integer>[] adj = new ArrayList[numCourses];

        for (int i = 0; i < numCourses; i++) {
            adj[i] = new ArrayList<Integer>();
        }

        for (int[] node: prerequisites) {
            indeg[node[1]]++;
            adj[node[0]].add(node[1]);
        }

        // finding nodes with indeg 0
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) que.add(i);
        }

        while (!que.isEmpty()) {
            int cur = que.poll();

            if (indeg[cur] == -1) return new int[0];

            indeg[cur] = -1;
            ans.add(cur);

            for (int nbr: adj[cur]) {
                indeg[nbr]--;
                if (indeg[nbr] == 0) que.add(nbr);
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] != -1) return new int[0];
        }

        Collections.reverse(ans);
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}