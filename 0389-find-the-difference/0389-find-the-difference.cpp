class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> map; 
        for (char i: s){
            if (map.find(i) == map.end()) map[i] = 1; 
            else map[i]++;
        }  
        

        for (char i: t){
            if (map.find(i) == map.end()) return i;
            else {
                map[i]--;
                if (map[i] == 0) map.erase(i);
            }
        }

        return ' ';
    }
};