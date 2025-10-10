class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length; 
        int positive = 0; 
        int negative = 1; 

        while(positive < n && negative < n) {
            if (nums[positive] > 0) {
                positive += 2;
            } else {
                swap(nums, positive, negative);
            }

            if (nums[negative] < 0) {
                negative += 2;
            } else {
                swap(nums, positive, negative);
            }
        }

        return nums;
    }

    private void swap (int[] arr, int i1, int i2) {
        int temp = arr[i1]; 
        arr[i1] = arr[i2]; 
        arr[i2] = temp;
    }
}