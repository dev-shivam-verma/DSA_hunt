class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        int low = 0, high = n - 1; 
        int idx = 0; 

        while (idx <= high) {
            int num = nums[idx];

            if (num == 2) {
                swap(nums, idx, high);
                high--; 
            } else if (num == 0) {
                swap(nums, idx, low);
                low++;
                idx++;
            } else {
                idx++;
            }
        }
    }

    public void swap(int[] arr, int i1, int i2) {
        int temp = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = temp; 
    }
}