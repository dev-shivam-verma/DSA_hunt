class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int i = 0, j = 0;
        int n = size(s);
        int max = 0;

        while (j < n) {
            if (set.find(s[j]) != set.end()) {
                while(s[i] != s[j]) {
                    set.erase(s[i]);
                    i++;
                }

                i++;
            }

            set.insert(s[j]);
            int len = j - i + 1;
            if (len > max) max = len;
            j++;
        }

        return max;
    }
};