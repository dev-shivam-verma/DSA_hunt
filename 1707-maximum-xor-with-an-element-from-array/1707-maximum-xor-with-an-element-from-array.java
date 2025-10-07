class Node{
    Node[] links; 

    public Node() {
        links = new Node[2];
    }

    public Node get(int i) {return links[i];}

    public void put(int i, Node node) {links[i] = node;}

    public boolean containsKey(int i) {return get(i) != null;}
}

class Trie {
    Node root; 

    public Trie() {
        root = new Node();
    }

    public void insert(int i) {
        Node temp = root;

        for (int x = 31; x >= 0; x--) {
            int bit = (i >> x) & 1;

            if (!temp.containsKey(bit)) {
                temp.put(bit, new Node());
            }

            temp = temp.get(bit);
        }
    }

    public int solveQuery(int x) {
        Node temp = root; 
        
        
        int result = 0;
        for (int i = 31; i >= 0; i--) {
            if (temp == null) return -1;

            int bit = (x >> i) & 1;

            if (temp.containsKey(bit ^ 1)) {
                result = result | 1 << i;
                bit = bit ^ 1;
            }

            temp = temp.get(bit);
        }

        return temp == null? -1: result;
    }
}

class Solution {
    public int[] maximizeXor(int[] nums, int[][] queries) {
        Arrays.sort(nums);
        
        int n = nums.length;
        int m = queries.length;
        int[][] _queries = new int[m][3];

        for (int i = 0; i < m; i++) {
            _queries[i] = new int[]{
                queries[i][0],
                queries[i][1],
                i
            };
        }

        Arrays.sort(_queries, (a, b)-> {
            return a[1] - b[1];
        });

        int[] result = new int[m];
        int idx = 0;
        Trie trie = new Trie();
        for (int[] query: _queries) {
            while(idx < n && nums[idx] <= query[1]) {
                trie.insert(nums[idx]);
                idx++; 
            }

            result[query[2]] = trie.solveQuery(query[0]);
        }

        return result;
    }
}