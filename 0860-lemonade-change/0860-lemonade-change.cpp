class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> hash;
        hash[5] = 0;
        hash[10] = 0;
        hash[20] = 0;

        for (int i: bills){
            hash[i]++;

            int r = i - 5;
            if (r == 0) continue;
            else if (r == 5) {
                if (hash[5] > 0) hash[5]--;
                else return false;
            } else if (r == 15){
                if (hash[10] > 0 && hash[5]>0){
                    hash[10]--; hash[5]--;
                } else if (hash[5] >= 3){
                    hash[5] -= 3;
                } else return false;
            }
        }


        return true;
    }
};