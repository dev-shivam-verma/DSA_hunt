class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int maxFreq = 0;

        for (int i: nums){
            if (freq.find(i) == freq.end()){
                freq[i] = 1;
            } else {
                freq[i]++;
            }

            if (i != k && freq[i] > maxFreq) maxFreq = freq[i]; 
        }

        

        if (freq.find(k) != freq.end()) maxFreq += freq[k];

        return maxFreq;
    }
};