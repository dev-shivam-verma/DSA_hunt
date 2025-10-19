class Solution {
    private int a; 
    private int b;

    public String findLexSmallestString(String s, int a, int b) {
        this.a = a; 
        this.b = b;

        return f("", s);
    }

    public String f(String prev, String curr) {
        if (prev.length() > 0 && prev.compareTo(curr) < 1) return ""; 

        String result = curr; 
        
        String op1 = f(curr, operation1(curr, a));
        String op2 = f(curr, operation2(curr, b));

        if (op1.length() > 0 && result.compareTo(op1) > 0) result = op1;
        if (op2.length() > 0 && result.compareTo(op2) > 0) result = op2;

        return result;         
    }

    public String operation1 (String s, int a) {
        int idx = 0; 
        String result = "";

        for (char c: s.toCharArray()) {
            if (idx % 2 != 0) {
                result += Character
                .forDigit(
                    (Character.getNumericValue(c) + a) % 10, 
                    10
                    ); 
            } else {
                result += c;
            }

            idx++;
        }

        return result;
    }


    public String operation2(String s, int k) {
        int n = s.length();
        k %= n;
        if (k == 0) return s;
        return s.substring(n - k) + s.substring(0, n - k);
    }
}