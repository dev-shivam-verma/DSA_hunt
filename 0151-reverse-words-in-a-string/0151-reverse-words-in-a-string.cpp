class Solution {
public:
    string reverseWords(string s) {
        vector<string> words = {};
        string result = "";

        for (int i = 0; i < s.length(); i++){
            string word = "";

            while (i < s.length() && s[i] != ' '){
                word += s[i];
            }

            if (word.length() > 0) words.push_back(word);
        }

        for (int i = words.size() - 1; i >= 0; i--){
            result += words[i];
            if (i != 0) result += " ";
        }

        return result;
    }
};