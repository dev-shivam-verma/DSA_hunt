class Solution {
public:
    int maxScore(string s) {
        int score = 0;
        int maxscore = 0;

        // initially counting all ones into score
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '1') score++;
        }        

        // finding max score
        for (int i = 1; i < s.length(); i++){

            //adjusting the score 
            if (s[i-1] == '0') score++;
            else if (s[i-1] == '1') score--;

            if (score > maxscore) maxscore = score;
        }


        return maxscore;
    }
};