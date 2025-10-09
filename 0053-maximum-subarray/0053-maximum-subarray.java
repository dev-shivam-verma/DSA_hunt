class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int maxSum = Integer.MIN_VALUE;
        int sum = 0; 

        for (int i: nums) {
            sum += i; 

            maxSum = Math.max(maxSum, sum);

            if (sum < 0) sum = 0;
        }

        return maxSum;
    }
}