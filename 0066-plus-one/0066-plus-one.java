class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;

        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] + carry < 10) {
                digits[i] += carry;
                carry = 0;
                break;
            } else {
                digits[i] = 10 - digits[i] - carry;
                carry = 1;
            }
        }

        if (carry == 1) {
            int[] new_digits = new int[n + 1];
            new_digits[0] = carry;
            return new_digits;
        }

        return digits;
    }
}