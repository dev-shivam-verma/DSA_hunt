class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        return f(word1, word2);
    }


    string f(string a, string b){
        if (a.size() == 0) return b;
        if (b.size() == 0) return a;
        
        return a[0] + string(b, a.substr(1));
    }
};