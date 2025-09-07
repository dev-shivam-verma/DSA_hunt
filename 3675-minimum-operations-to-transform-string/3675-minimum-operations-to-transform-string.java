class Solution {
    public int minOperations(String s) {
        // index of 'a' is 0 && z is '25'
        int lowestIdx = 26;

        for (char i: s.toCharArray()) {
            int idx = i - 'a';
            if (idx != 0) {
                lowestIdx = Math.min(lowestIdx, idx);
            }
        }

        return lowestIdx == 26? 0: 26 - lowestIdx;
    }
}