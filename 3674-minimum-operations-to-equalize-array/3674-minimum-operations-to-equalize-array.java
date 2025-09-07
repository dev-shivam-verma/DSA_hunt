class Solution {
    public int minOperations(int[] nums) {
        boolean isAllEqual = true;
        int aggrAnd = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) isAllEqual = false;
        }

        return isAllEqual ? 0: 1;
    }
}