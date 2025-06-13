class Node {
    String word;
    int level;

    Node(String word, int level) {
        this.word = word;
        this.level = level;
    }
}

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> words = new HashSet<>(wordList);
        Queue<Node> que = new LinkedList<>();

        Node first = new Node(beginWord, 1);
        que.add(first);
        words.remove(beginWord);

        while (!que.isEmpty()) {
            Node current = que.poll();

            if (current.word.equals(endWord)) return current.level;

            StringBuilder word = new StringBuilder(current.word);
            for (int i = 0; i < word.length(); i++) {
                for (char a = 'a'; a < 'z' + 1; a++) {
                    word.setCharAt(i,a);
                    
                    if (words.remove(word.toString())) {
                        Node next = new Node(word.toString(), current.level + 1);

                        que.add(next);
                    }
                }
                word = new StringBuilder(current.word);
            }            
        }

        return 0;

    }

    
    

}