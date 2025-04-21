class Solution {
public:
    bool checkValidString(string s) {
        list<char> stk1;
        list<char> stk2;


        for (char i: s){
            if (i == '*') {
                stk1.push_back(i);
                if (!stk2.empty()) {
                    stk2.pop_back();
                    stk1.push_back(i);
                    }
            }
            else if (i == '(') stk2.push_back(i);
            else {
                if (!stk2.empty()) stk2.pop_back();
                else if (!stk1.empty()) stk1.pop_back();
                else return false;
            }
        }

        

        return stk2.empty();
    }
};