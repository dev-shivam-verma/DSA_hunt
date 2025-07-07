class Solution {
    public boolean isMonotonic(int[] nums) {
        boolean isDecreasing = true;
        boolean isIncreasing = true;

        int n = nums.length;

        // is decreasing 
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                isDecreasing = false;
            }

            if (nums[i] < nums[i - 1]) {
                isIncreasing = false;
            }
        }

        return isDecreasing || isIncreasing;
    }
}