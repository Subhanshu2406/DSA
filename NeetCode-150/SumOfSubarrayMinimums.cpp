class Solution {
public:
    int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> nextSmallest;
        unordered_map<int,int> prevSmallest;
        stack<int> stk;

        //for nextSmallest
        for(int i = 0;i < n; i++){
            while(!stk.empty() && arr[stk.top()] > arr[i]){
                nextSmallest[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            nextSmallest[stk.top()] = n;
            stk.pop();
        }

        //now for prevSmallest
        for(int i = n-1;i >= 0; i--){
            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                prevSmallest[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            prevSmallest[stk.top()] = -1;
            stk.pop();
        }

        int res = 0;

        for(int i = 0;i < n;i ++){
            long long left = i - prevSmallest[i];
            long long right = nextSmallest[i] - i;
            long long contrib = (arr[i] % MOD) * (left % MOD) % MOD * (right % MOD) % MOD;
            res = (res + contrib) % MOD;
        }
        //(a⋅b⋅c)%M=(((a%M)⋅(b%M))%M⋅(c%M))%M
        return res % MOD;
    }
};