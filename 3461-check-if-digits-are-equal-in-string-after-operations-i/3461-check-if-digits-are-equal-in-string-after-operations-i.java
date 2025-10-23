class Solution {
    public boolean hasSameDigits(String s) {
        String result = s; 
        while (result.length() > 2){
            String temp = "";
            for (int i = 0; i < result.length() - 1; i++) {
                int value = Integer.valueOf(result.charAt(i)) + Integer.valueOf(result.charAt(i + 1));

                value %= 10;
                temp += Character.forDigit(value, 10);
            }

            result = temp;
        }


        return result.charAt(0) == result.charAt(1);
    }
}