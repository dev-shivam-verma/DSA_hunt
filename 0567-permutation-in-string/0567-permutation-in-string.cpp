class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash(26,0);
        vector<int> windowFreq(26,0);
        
        for (int i = 0; i < size(s1); i++) {
            hash[s1[i] - 'a']++;
        }


        int start= 0; 
        int n = size(s2);

        for (int i = 0; i < n; i++) {
            if (i < size(s1)) {
                windowFreq[s2[i] - 'a']++;
            } else {
                windowFreq[s2[i] - 'a']++;
                windowFreq[s2[start++] - 'a']--;
            }


            // matching freq;
            for (int x = 0; x < 26; x++) {
                if (hash[x] != windowFreq[x]) break;
                if (x == 25 && hash[x] == windowFreq[x]) return true;
            }
        }

       
        return false;
    }
};