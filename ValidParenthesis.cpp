class Solution {
    public:
        bool isValid(string s) {
            stack<char> stack;
             for(char c : s){
                if(c == '{' || c == '[' || c == '(') stack.push(c);
                else if((c == '}' || c == ']' || c == ')') && !stack.empty()){
                    if( (c == '}' && stack.top() == '{') || (c == ']' && stack.top() == '[') || (c == ')' && stack.top() == '(')) stack.pop();
                    else return false;
                }
                else return false;
             }
    
             if(stack.empty()) return true;
    
            return false;
        }
    };