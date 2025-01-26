class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        
        for (int num: nums){
            total += num;
        }
        

        int count = 0;
        int leftSum = 0;
        
        for (int i = 0; i < nums.size() - 1; i++){
            leftSum += nums[i];
            int rightSum = total - leftSum;

            if ((rightSum - leftSum) % 2 == 0) count++;
        }

        return count;
    }
};