class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 1) return cost[0];
        vector<int> dp(n);
        dp[0] = cost[n-1];
        dp[1] = cost[n-2];

        for(int i = 2; i < n ; i++){
            dp[i] = cost[n - i - 1] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};