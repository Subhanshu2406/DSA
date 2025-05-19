class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stack;
        for(string s : tokens){
            if(s == "+" || s == "-" || s == "/" || s == "*"){
                int number1 = stoi(stack.top());
                stack.pop();
                int number2 = stoi(stack.top());
                stack.pop();
                if(s == "+") stack.push(to_string(number2 + number1));
                else if(s == "-") stack.push(to_string(number2 - number1));
                else if(s == "*") stack.push(to_string(number2 * number1));
                else if(s == "/") stack.push(to_string(number2 / number1));
            }
            else stack.pop(s);
        }
        return stack.top();
    }
};
