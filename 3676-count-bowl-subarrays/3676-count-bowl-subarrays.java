class Solution {
    public long bowlSubarrays(int[] nums) {
        if (nums.length < 3) return 0;
        int n = nums.length;

        int[] nextBig = new int[n];
        Stack<Integer> nextBigStk = new Stack<>();
        nextBigStk.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!nextBigStk.isEmpty() && nums[nextBigStk.peek()] <= nums[i]) nextBigStk.pop();

            if (!nextBigStk.isEmpty()) {
                nextBig[i] = nextBigStk.peek();
            } else {
                nextBig[i] = i;
            }

            nextBigStk.push(i);
        }

        int bowls = 0;

        Stack<Integer> prevBigStk = new Stack<>();
        prevBigStk.push(0);
        for (int i = 1; i < n - 1; i++) {
            while (!prevBigStk.isEmpty() && nums[prevBigStk.peek()] <= nums[i]) prevBigStk.pop();

            if (!prevBigStk.isEmpty() && nextBig[i] != i ) {
                bowls++;
            }

            prevBigStk.push(i);
        }

        return bowls;
    }
}