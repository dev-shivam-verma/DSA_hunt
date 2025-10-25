class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0, j = 0; 

        int obsr = nums[0];
        int freq = 0;

        while (i < nums.length) {
            if (nums[i] == obsr) freq++; 
            else {
                obsr = nums[i];
                freq = 1;
            }

            if (freq <= 2) {
                nums[j] = nums[i];
                j++;
            }

            i++;
        }

        return j;
    }

}