class Solution {
public:
    bool isValid(string s) {

        vector<int> stack;
        for(char i: s){
            switch(i){
                case '(': stack.push_back(')');
                    break;
                case '{': stack.push_back('}');
                    break;
                case '[': stack.push_back(']');
                    break;
                case ')': 
                    if (stack.back() == ')') stack.pop_back();
                    else return false;
                    break;
                case '}': 
                    if (stack.back() == '}') stack.pop_back();
                    else return false;
                    break;
                case ']': 
                    if (stack.back() == ']') stack.pop_back();
                    else return false;
                    break;
            }
        }


        return stack.size() == 0;
    }
};