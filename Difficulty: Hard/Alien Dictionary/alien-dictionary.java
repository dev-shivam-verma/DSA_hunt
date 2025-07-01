class Solution {
    public String findOrder(String[] words) {
        // Graph building
        Map<Character, Set<Character>> graph = new HashMap<>();
        int[] indeg = new int[128];

        // Initialize graph and indegree array
        for (String word : words) {
            for (char ch : word.toCharArray()) {
                graph.putIfAbsent(ch, new HashSet<>());
            }
        }

        // Build edges
        for (int i = 0; i < words.length - 1; i++) {
            String w1 = words[i];
            String w2 = words[i + 1];
            int minLen = Math.min(w1.length(), w2.length());

            boolean found = false;
            for (int j = 0; j < minLen; j++) {
                char c1 = w1.charAt(j), c2 = w2.charAt(j);
                if (c1 != c2) {
                    if (!graph.get(c1).contains(c2)) {
                        graph.get(c1).add(c2);
                        indeg[c2]++;
                    }
                    found = true;
                    break;
                }
            }

            // Edge case: prefix conflict (["abc", "ab"]) → invalid
            if (!found && w1.length() > w2.length()) return "";
        }

        // Topological sort
        Queue<Character> que = new LinkedList<>();
        for (char ch : graph.keySet()) {
            if (indeg[ch] == 0) {
                que.offer(ch);
            }
        }

        StringBuilder order = new StringBuilder();

        while (!que.isEmpty()) {
            char cur = que.poll();
            order.append(cur);

            for (char nei : graph.get(cur)) {
                indeg[nei]--;
                if (indeg[nei] == 0) que.offer(nei);
            }
        }

        return order.length() == graph.size() ? order.toString() : "";
    }
}
