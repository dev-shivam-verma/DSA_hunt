class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        vector<int> prefixSum;

        // calculating sum of  subarrays
        for (int i = 0; i<n; i++){
            int start = max(0, i - nums[i]);

            // calculating prefix sum
            if (i == 0){
                prefixSum.push_back(nums[i]);
            } else {
                prefixSum.push_back(prefixSum[i - 1] + nums[i]);
            }

            int subSum;
            if (start != 0){
                subSum = prefixSum[i] - prefixSum[start - 1];
            } else {
                subSum = prefixSum[i]; 
            }

            sum += subSum;
        }

        return sum;
    }
};