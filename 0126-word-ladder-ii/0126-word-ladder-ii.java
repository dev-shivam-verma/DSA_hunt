class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> ans = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        Map<String, List<String>> parent = new HashMap<>();
        Queue<String> que = new LinkedList<>();
        Set<String> words = new HashSet<>(wordList);

        if (!words.contains(endWord)) return ans;

        map.put(beginWord, 0);
        que.add(beginWord);

        while (!que.isEmpty()) {
            int size = que.size();
            Set<String> visitedThisLevel = new HashSet<>();

            for (int k = 0; k < size; k++) {
                String cur = que.poll();

                StringBuilder word = new StringBuilder(cur);
                for (int i = 0; i < cur.length(); i++) {
                    char original = word.charAt(i);
                    for (char a = 'a'; a <= 'z'; a++) {
                        if (a == original) continue;
                        word.setCharAt(i, a);
                        String next = word.toString();

                        if (words.contains(next)) {
                            if (!map.containsKey(next)) {
                                map.put(next, map.get(cur) + 1);
                                que.add(next);
                                visitedThisLevel.add(next);
                            }

                            // If next is reachable in one step from cur
                            if (map.get(next) == map.get(cur) + 1) {
                                parent.computeIfAbsent(next, key -> new ArrayList<>()).add(cur);
                            }
                        }
                    }
                    word.setCharAt(i, original); // restore
                }
            }

            words.removeAll(visitedThisLevel);
        }

        if (map.containsKey(endWord)) {
            List<String> path = new ArrayList<>();
            path.add(endWord);
            dfs(endWord, beginWord, parent, path, ans);
        }

        return ans;
    }

    void dfs(String word, String beginWord, Map<String, List<String>> parent, List<String> path, List<List<String>> ans) {
        if (word.equals(beginWord)) {
            List<String> temp = new ArrayList<>(path);
            Collections.reverse(temp);
            ans.add(temp);
            return;
        }

        if (!parent.containsKey(word)) return;

        for (String prev : parent.get(word)) {
            path.add(prev);
            dfs(prev, beginWord, parent, path, ans);
            path.remove(path.size() - 1);
        }
    }
}
