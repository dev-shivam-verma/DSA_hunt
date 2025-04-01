class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int windowSize = 0;
        list<int> maxDeque;
        vector<int> ans;
        

        for (int i = 0; i < nums.size(); i++){
            while (!maxDeque.empty() && maxDeque.back() < nums[i]){
                maxDeque.pop_back();
            }

            if (windowSize < k){
                windowSize++;
            } else {
                if (maxDeque.front() == nums[i - k]){
                    maxDeque.pop_front();
                }
            }

            maxDeque.push_back(nums[i]);
            if (i >= k - 1){
                ans.push_back(maxDeque.front());
            }
        }


       return ans;
    }

};