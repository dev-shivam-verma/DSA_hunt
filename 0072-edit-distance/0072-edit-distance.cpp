class Solution {
public:
    int minDistance(string word1, string word2) {
        int x = word1.size(), y = word2.size();

        vector<int> prev(y + 1, 0);
        vector<int> cur(y + 1, 0);

        // base case
        for (int j = 0; j <= y; j++){
            prev[j] = j;
        } 

        // tabulation with space optemization
        for (int i = 1; i <= x; i++){

            // base case
            cur[0] = i;

            for (int j = 1; j <= y; j++){
                if(word1[i - 1] == word2[j -1]) cur[j] = prev[j - 1];
                else {
                    cur[j] = 1 + min(cur[j - 1], min(prev[j - 1], prev[j]));
                }
            }

            prev = cur;
        }

        return prev[y];
    }

    int f(int i, int j, string s1, string s2){
        if (i < 0) return j + 1;
        if (j < 0) return i + 1; 
        
        if (s1[i] == s2[j]) return f(i - 1, j - 1, s1, s2);
        return 1 + min(f(i , j - 1, s1,s2), min(f(i - 1, j - 1, s1, s2), f(i - 1, j, s1, s2)));
    }
};