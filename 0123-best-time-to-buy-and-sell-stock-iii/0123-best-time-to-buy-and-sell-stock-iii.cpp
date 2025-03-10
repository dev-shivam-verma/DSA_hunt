class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prev(5, 0);
        vector<int> cur(5, 0);

        for (int idx = prices.size() - 1; idx >= 0; idx--){
            for (int trans = 3; trans >= 0; trans--){
                int trade = 0;

                // trade
                if (trans == 0 || trans == 2){
                    // buy
                    trade = prev[trans + 1] - prices[idx];
                } else if (trans == 1 || trans == 3){
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

    int f(int idx, int trans, vector<int>& prices){
        if (idx == prices.size()) return 0;

        int trade = 0;
        // trade
        if (trans == 0 || trans == 2){
            // buy
            trade = f(idx + 1, trans + 1, prices) - prices[idx];
        } else if (trans == 1 || trans == 3){
            // sell
            trade = f(idx, trans + 1, prices) + prices[idx];
        }


        // not trade
        int notTrade = f(idx + 1, trans, prices);

        return max(trade, notTrade);
    }
};