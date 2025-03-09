class Solution {
public:
    int minDistance(string s1, string s2) {
        int x = s1.size(), y = s2.size();
        
        vector<int> prev(y + 1, 0);
        vector<int> cur(y + 1, 0);
        
        for (int i = 1; i <= x; i++){
            for (int j = 1; j <= y; j++){
                if (s1[i-1] == s2[j-1]){ 
                    cur[j] = prev[j-1] + 1; 
                    }
                else {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }
            
            prev = cur;
        }   


        return x + y - (2 * prev[y]);
    }
};