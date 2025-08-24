class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int left = 0;
        int right = 0;
        int counter = 0;
        while(right < s.size()){
            if(s[right] == '(') counter++;
            else if(s[right] == ')') counter --;
            if(counter < 0){
                counter = 0;
                left = right + 1;
            }
            else if(counter == 0) res = max(res,(right - left + 1));
            right++;
        }
        
        right = s.size() - 1;
        left = right;
        counter = 0;
        while(left >= 0){
            if(s[left] == ')') counter++;
            else if(s[left] == '(') counter --;
            if(counter < 0){
                counter = 0;
                right = left - 1;
            }
            else if(counter == 0) res = max(res,(right - left + 1));
            left--;
        }
        return res;
    }
};



//using stack solution
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for(int i = 0;i < s.size() ; i++){
            if(s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if(stk.empty()) {
                    stk.push(i);  // new base
                } else {
                    res = max(res, i - stk.top());
                }
            }
        }
        return res;
    }
};


