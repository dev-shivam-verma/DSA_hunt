class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n; 

        int[] copy = Arrays.copyOf(nums, n);


        for (int i = 0; i < n; i++) {
            int rotatedIdx = (i + k) % n;
            nums[rotatedIdx] = copy[i];
        }
    }
}