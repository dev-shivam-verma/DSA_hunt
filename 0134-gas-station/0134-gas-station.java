class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) { 
        int n = gas.length;
        int tgas = 0; 
        int tcost = 0; 

        for (int i = 0; i < n; i++) {
            tgas += gas[i];
            tcost += cost[i];
        }

        if (tgas < tcost) return -1;

        int start = 0; 
        int curGas = 0; 

        for (int i = 0; i < n; i++) {
            curGas += gas[i] - cost[i];

            if (curGas < 0) {
                curGas = 0; 
                start = i + 1;
            }
        }


        return start; 
    }
}