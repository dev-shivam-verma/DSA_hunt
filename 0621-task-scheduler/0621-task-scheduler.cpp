class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26, 0);
        int max = 0;
        int maxCount = 0;

        for(char i: tasks){
            hash[i - 'A']++;
            if(max == hash[i - 'A']) {
                maxCount++;
            }
            else if(max < hash[i - 'A']) {
                max = hash[i - 'A'];
                maxCount = 1;
            }
        }

        int partCount = max - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - max * maxCount;
        int idles = std::max(0, emptySlots - availableTasks);        
        
        return tasks.size() + idles ;
    }
};