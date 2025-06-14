class Solution {
    
    public List<String> letterCombinations(String digits) {
        List<String> mapping = new ArrayList<>();
        mapping.add("");
        mapping.add("");
        mapping.add("abc");
        mapping.add("def");
        mapping.add("ghi");
        mapping.add("jkl");
        mapping.add("mno");
        mapping.add("pqrs");
        mapping.add("tuv");
        mapping.add("wxyz");

        List<String> combinations = new ArrayList<>();
        if (digits.length() == 0) return combinations;
        f(0, digits,new StringBuilder(), combinations, mapping);


        return combinations;                
    }


    void f(int idx, String digits, StringBuilder combination, List<String> combinations, List<String> mapping){
        if (idx == digits.length()) {
            combinations.add(combination.toString());
            return;
        }

        int digit = digits.charAt(idx) - '0';
        for (char a: mapping.get(digit).toCharArray()) {
            combination.append(a);
            f(idx + 1, digits, combination, combinations, mapping);
            combination.deleteCharAt(combination.length() - 1); // backtrack
        }
    }
}