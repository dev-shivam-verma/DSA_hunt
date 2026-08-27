class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> charMap(128,0);

        for (int i = 0; i < size(t); i++) {
            charMap[t[i]]++;
        }

        int charFound = 0; 
        int i = 0;
        int minWindow[2] = {0,INT_MAX};
        
        for (int j = 0; j < size(s); j++) {
            char ch = s[j];

            if (charMap[ch] > 0) {
                charFound++;
            }
            charMap[ch]--;

            if (charFound == size(t)) {
                int stChar = s[i];
                while(charMap[stChar] != 0) {
                    charMap[stChar]++;
                    i++;
                    stChar = s[i];
                }

                if (j - i < minWindow[1] - minWindow[0]) {
                    minWindow[0] = i;
                    minWindow[1] = j;
                }

                charMap[stChar]++;
                charFound--;
                i++;
            }
        }


        return minWindow[1] == INT_MAX? "": s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
    }
};