class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> pprev(2, 0);
        vector<int> prev(2, 0);
        vector<int> cur(2, 0);

        // tabulation with space optemization
        for (int idx = prices.size() - 1; idx >= 0; idx--){
            for (int buy = 0; buy <= 1; buy++){
                int trade = 0;

                // trade 
                if (buy > 0){
                    // sell 
                    trade = prices[idx] + pprev[0];
                } else {
                    // buy
                    trade = prev[1] - prices[idx];
                }

                // not trade
                int notTrade = prev[buy];

                cur[buy] = max(trade, notTrade);
            }

            pprev = prev;
            prev = cur;
        }

        return prev[0];
    }

    int f(int idx, int buy, vector<int>& prices){
        if (idx >= prices.size()) return 0;

        // perform trade or not
        int trade = 0;
        if (buy > 0){
            // sell
            trade = prices[idx] + f(idx + 2, 0, prices);
        } else {
            // buy
            trade = f(idx + 1, 1, prices) - prices[idx];
        }

        int notTrade = f(idx + 1, buy, prices);

        return max(trade, notTrade);
    }
};