// User function Template for Java

class Solution {
    int minimumMultiplications(int[] arr, int start, int end) {

        // Your code here
        Set<Integer> visited = new HashSet<>();
        
        Queue<int[]> que = new LinkedList<>();
        que.add(new int[] {start, 0});

        while (!que.isEmpty()) {
            int[] cur = que.poll();
            int node = cur[0];
            int steps = cur[1];

            if (node == end) return steps;
            for (int nbr: arr) {
                int nNode = (node * nbr) % 100000;

                if (!visited.contains(nNode)) {
                    visited.add(nNode);
                    que.add(new int[] {nNode, steps + 1});
                }
            }
        }
       
        return -1;
    }
}
