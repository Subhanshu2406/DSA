class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        int i = 0;
        stack<char> stk;
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && k > 0 && stk.top() > num[i]) {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }

        while(k > 0){
            stk.pop();
            k--;
        }
        string res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        
        reverse(res.begin(), res.end());
        int l = 0;
        while(l < res.size() && res[l] == '0') l++;

        if(l >= res.size()) return "0";

        return res.substr(l, res.size() - l);
    }
};
