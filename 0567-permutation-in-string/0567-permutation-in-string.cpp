class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() - s1.length() < 0) return false;

        int ogFrequency[26] = {0};
        int slidingFrequency[26] = {0};
        int windStr = 0;

        for (int i: s1){
            ogFrequency[i - 'a']++;
        }       

        for (int x = 0; x < s2.length(); x++){

            if (x <= s1.length() - 1){
                //calculating frequency of characters
                slidingFrequency[s2[x] - 'a']++;
            } else {

                //calculating frequency of characters
                slidingFrequency[s2[windStr++] - 'a']--;
                slidingFrequency[s2[x] - 'a']++;
            }


            // matching the frequencies
            if (x >= s1.length() - 1){
                for (int i = 0; i < 26; i++){
                    if (slidingFrequency[i] != ogFrequency[i]) break;
                    else if (i == 25) return true;
                }
            }
        }    


        return false;  
    }
};