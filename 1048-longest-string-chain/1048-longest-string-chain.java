class Solution {
    public int longestStrChain(String[] words) {
        int n = words.length;
        int[] chainLengths = new int[n];
        Arrays.fill(chainLengths, 1);
        Arrays.sort(words, (a,b) -> Integer.compare(a.length(), b.length()));

        for (int i = 0; i < n; i++) {
            
            for (int j = 0;  j < i; j++) {
                if (isAPredOfB(words[j], words[i])) {
                    chainLengths[i] = Math.max(chainLengths[i], chainLengths[j] + 1);
                }
            }
        }
        
        return Arrays.stream(chainLengths).max().getAsInt();
    }

    

    private boolean isAPredOfB(String a, String b) {
        if (a.length() + 1 != b.length()) return false;
        
        int i = 0, j = 0;
        while (i < a.length() && j < b.length()) {
            if (a.charAt(i) == b.charAt(j)) {
                i++; j++;
            } else {
                j++; // skip one character in b
            }
        }
        return i == a.length(); // all of a must be matched
    }

}