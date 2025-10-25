class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0; 
        int j = nums.length - 1; 


        while (i <= j && i < nums.length) {
            while (i <= j && nums[j] == val) j--;
            if (j < i) break;
            
            if (nums[i] == val) {
                swap(nums, i, j);
            }

            i++;
        }

        return i;
    }

    public void swap(int[] nums, int i1, int i2) {
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
    }
}