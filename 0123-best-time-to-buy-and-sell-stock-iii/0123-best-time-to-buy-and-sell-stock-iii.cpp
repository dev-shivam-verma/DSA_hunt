class Solution {
public:


    int maxProfit(vector<int>& Arr) {

        int n = Arr.size();
        // Create two 2D arrays to store the profit information, one for the current state and one for the ahead state.
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 0) { // We can buy the stock
                        cur[buy][cap] = max(0 + ahead[0][cap], 
                                            -Arr[ind] + ahead[1][cap]);
                    }

                    if (buy == 1) { // We can sell the stock
                        cur[buy][cap] = max(0 + ahead[1][cap],
                                            Arr[ind] + ahead[0][cap - 1]);
                    }
                }
            }
            // Update the ahead state with the current state for the next iteration.
            ahead = cur;
        }

        return ahead[0][2];
    }
    // int maxProfit(vector<int>& prices) {
    //     vector<int> prev(5, 0);
    //     vector<int> cur(5, 0);


    //     // tabulation with space optemization
    //     for (int idx = prices.size() - 1; idx >= 0; idx--){
    //         for (int trans = 3; trans >= 0; trans--){
    //             int trade = 0;

    //             // trade
    //             if (trans == 0 || trans == 2){
    //                 // buy
    //                 trade = prev[trans + 1] - prices[idx];
    //             } else if (trans == 1 || trans == 3){
    //                 // sell
    //                 trade = cur[trans + 1] + prices[idx];
    //             }

    //             // not trade
    //             int notTrade = prev[trans];

    //             cur[trans] = max(trade, notTrade);
    //         }

    //         prev = cur;
    //     }

    //     return prev[0];
    // }

    
};