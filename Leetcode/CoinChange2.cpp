class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(amount + 1, vector<int>(n + 1, 0));

        for(int i = 0;i < n;i++) dp[0][i] = 1;

        for(int i = 1; i <= amount; i++){
            for(int j = coins.size() - 1 ;j >= 0; j++){
                if(i - coins[j] >= 0) dp[i][j] += dp[i-coins[j]][j];
                dp[i][j] += dp[i][j+1];
            }
        }

        return dp[amount][coins.size() - 1];
    }
};