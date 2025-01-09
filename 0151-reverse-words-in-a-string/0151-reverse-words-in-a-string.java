class Solution {
    public String reverseWords(String s) {
        List<String> words = new ArrayList<>();
        String result = "";
        
        for (int i = 0; i < s.length(); i++){
            String word = "";

            while (i < s.length() && s.charAt(i) != ' '){
                word += s.charAt(i);
                i++;
            }

            if (word.length() > 0) words.add(word);
        }

        for (int i = words.size() - 1; i >= 0; i--){
            result += words.get(i);
            if (i != 0) 
                result += " ";
        }

        return result;
    }

}