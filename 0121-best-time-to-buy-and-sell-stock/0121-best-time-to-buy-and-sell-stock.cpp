class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 0;
        int maxProfit = 0;

        for (int j = 1; j < prices.size(); j++){
            maxProfit = max(maxProfit, prices[j] - prices[mini]);
            if (prices[j] < prices[mini]) mini = j;
        }

        return maxProfit;
    }
};