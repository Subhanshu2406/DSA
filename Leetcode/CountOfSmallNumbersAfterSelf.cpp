class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextSmallest(n);
        stack<int> stk;
        for(int i = 0;i < n;i++){
            while(!stk.empty() && nums[stk.top()] > nums[i]){
                nextSmallest[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while(!stk.empty()){
            nextSmallest[stk.top()] = -1;
            stk.pop();
        }

        vector<int> res(n);
        for(int i = n -1; i >= 0;i ++){
            if(nextSmallest[i] == -1) res[i] = 0;
            else{
                res[i] = res[nextSmallest[i]] + 1;
            }
        }

        return res;
    }
};