class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> prev(2, 0);
        vector<int> cur(2, 0);

        // tabulation with space optemization
        for (int idx = prices.size() - 1; idx >= 0; idx--){
            for (int buy = 0; buy <= 1; buy++){
                int trade = 0;

                // trade 
                if (buy > 0){
                    // sell 
                    trade = prices[idx] + cur[0];
                } else {
                    // buy
                    trade = prev[1] - prices[idx] - fee;
                }

                // not trade
                int notTrade = prev[buy];

                cur[buy] = max(trade, notTrade);
            }

            prev = cur;
        }

        return prev[0];
    }
};