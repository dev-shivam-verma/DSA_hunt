class Node {
    Node[] links; 
    
    public Node(){
        links = new Node[26];
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
}



class GfG {
    
    
    public static int countDistinctSubstring(String st) {
        Node root = new Node();
        
        int count = 0;
        
        for (int i = 0; i < st.length(); i++) {
            Node temp = root; 
            
            for (int j = i; j < st.length(); j++) {
                if (!temp.containsKey(st.charAt(j))) {
                    count++; 
                    temp.set(st.charAt(j), new Node());
                }
                
                temp = temp.get(st.charAt(j));
            }
        }
        
        // also counting the empty substr
        return ++count;
    }
}