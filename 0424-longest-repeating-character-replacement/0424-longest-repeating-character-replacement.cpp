class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> map(26, 0);
        int i = 0; 
        int j = 0; 
        int n = size(s);
        int maxfreq = 0;
        int maxlen = 0;

        while(j < n) {
            map[s[j] - 'A']++;
            maxfreq = max(maxfreq, map[s[j] - 'A']);
            
            
            if ((j-i+1)  - maxfreq > k) {
                map[s[i] - 'A']--;
                i++;
            }

            int len = j-i+1;
            maxlen = max(maxlen, len);
            j++;
        }

        return maxlen;
    }
};