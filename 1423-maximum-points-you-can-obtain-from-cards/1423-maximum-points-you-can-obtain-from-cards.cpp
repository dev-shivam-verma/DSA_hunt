class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int window = n - k;
        int total = 0;
        vector<int> prefixsum;
        for (int i: cardPoints) {
            total += i;
            prefixsum.push_back(total);    
        }
        if (window == 0) return total;

        int ans = 0;

        for (int i = 0; i < n; i++){
            if (i - window + 1 >= 0){
                int left = i - window + 1;
                int sum = left == 0? prefixsum[i]: prefixsum[i] - prefixsum[left - 1];

                ans = max(total - sum, ans);
            }
        }



        return ans;
    }
};