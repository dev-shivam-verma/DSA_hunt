class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<long> prev (amount + 1, 0);
        vector<long> cur (amount + 1, 0);

        // base case
        for (int amt = 0; amt <= amount; amt++){
            if (amt % coins[0] == 0) prev[amt] = 1;
        }

        // tabulation with space optemization 
        for (int idx = 1; idx < coins.size(); idx++){
            for (int amt = 0; amt <= amount; amt++){
                long int notTake = prev[amt];
                long int take = 0;

                if (amt >= coins[idx]){
                    take = cur[amt - coins[idx]];
                }

                cur[amt] = take + notTake;
            }

            prev = cur;
        }

        return prev[amount];
    }

    int recursion(int idx, int amount,vector<int> &coins){
 
        if (idx == 0){
            if (amount % coins[0] == 0) return 1;
            return 0;
        }

        int notTake = recursion(idx - 1, amount, coins);
        int take = 0;

        if (amount >= coins[idx]){
            take = recursion(idx, amount - coins[idx], coins);
        }

        return notTake + take;
    }
};