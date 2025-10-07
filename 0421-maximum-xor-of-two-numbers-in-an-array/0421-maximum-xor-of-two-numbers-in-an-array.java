class Node{
    Node[] links; 
    
    public Node() {links = new Node[2];}

    public Node get(int i) {return links[i];}

    public void put(int i, Node node) {links[i] = node;}

    public boolean containsKey(int i) {return get(i) != null;}
}

class Trie{
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

    public int getMaxXor(int x) {
        Node temp = root; 

        int result = 0; 
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1; 
            
            result = result<<1;
            if (temp.containsKey(bit ^ 1)) {
                result = result | 1; 
                bit = bit ^ 1;
            }

            temp = temp.get(bit);
        }

        return result;
    }
}


class Solution {
    public int findMaximumXOR(int[] nums) {
        if (nums.length < 2) return 0; 
        Trie trie = new Trie();

        trie.insert(nums[0]);

        int result = 0;
        for (int i = 1; i < nums.length; i++) {
            int max = trie.getMaxXor(nums[i]);

            result = Math.max(result, max);
            trie.insert(nums[i]);
        }

        return result; 
    }
}