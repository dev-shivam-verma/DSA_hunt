class Solution {
public:
    int countPrimes(int n) {

        vector<int> check(n + 1, 1);
        int ans = 0;

        for (int i = 2; i < n; i++){

            if (check[i] == 1){
                ans++;
                for (long long  j = (long long )i * i; j < n; j += i){
                    check[j] = 0;
                }
            }
        }

        return ans;
    }
};