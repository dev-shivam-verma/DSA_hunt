class Node {
    private Node[] links;
    private boolean flag; 
    
    
    public Node() {
        links = new Node[26];
        flag = false;
    }
    
    public Node get(char ch) {
        return links[ch - 'a'];
    }
    
    public void set(char ch, Node node) {
        links[ch - 'a'] = node;
    }
    
    public boolean containsKey(char ch) {
        return get(ch) != null;
    }
    
    public void setFlag() {flag = true; }

    public boolean getFlag() {return flag;}
}

class Trie {
    private Node root; 
    
    public Trie() {
        root = new Node();
    }
    
    public void insert(String word) {
        Node temp = root;
        
        for (char ch: word.toCharArray()) {
            if (!temp.containsKey(ch)) {
                temp.set(ch, new Node());
            }
            
            temp = temp.get(ch);
        }
        
        temp.setFlag();
    }
    
    public boolean haveEveryPrefix(String word) {
        Node temp = root; 
        
        for (char ch: word.toCharArray()) {
            if (temp.containsKey(ch)) {
                temp = temp.get(ch);
                
                if (!temp.getFlag()) return false; 
            }
            else return false;
        }
        
        return true;
    }
    
}



class Solution {
    public String longestString(String[] words) {
        Trie dict = new Trie();
        
        for (String word: words) {
            dict.insert(word);
        }
        
        String longest = "";
        
        for (String word: words) {
            if (dict.haveEveryPrefix(word)) {
                if (word.length() > longest.length() || word.length() == longest.length() && word.compareTo(longest) < 0) {
                    longest = word;
                }
            }
        }
        
        return  longest;
    }
    
}

