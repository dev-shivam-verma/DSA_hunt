class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> prev(2 * k + 1, 0);
        vector<int> cur(2 * k + 1, 0);


        // tabulation with space optemization
        for (int idx = prices.size() - 1; idx >= 0; idx--){
            for (int trans = 2 * k - 1; trans >= 0; trans--){
                int trade = 0;

                // trade
                if (trans % 2 == 0){
                    // buy
                    trade = prev[trans + 1] - prices[idx];
                } else {
                    // sell
                    trade = cur[trans + 1] + prices[idx];
                }

                // not trade
                int notTrade = prev[trans];

                cur[trans] = max(trade, notTrade);
            }

            prev = cur;
        }

        return prev[0];
    }
};