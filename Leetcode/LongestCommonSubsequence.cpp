class Solution {
public:
    vector<vector<int>> memo;

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        memo.assign(m, vector<int>(n, -1));
        return dfs(text1, text2, 0, 0);
    }

    int dfs(string& text1, string& text2, int i, int j) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (text1[i] == text2[j]) {
            memo[i][j] = 1 + dfs(text1, text2, i + 1, j + 1);
        } else {
            memo[i][j] = max(dfs(text1, text2, i + 1, j),
                             dfs(text1, text2, i, j + 1));
        }
        return memo[i][j];
    }
};


class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m,0));

        if (text1[0] == text2[0]) dp[0][0] = 1;

        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0];
            if (text1[i] == text2[0]) dp[i][0] = 1;
        }

        for (int j = 1; j < m; j++) {
            dp[0][j] = dp[0][j - 1];
            if (text1[0] == text2[j]) dp[0][j] = 1;
        }


        for(int i = 1; i < n; i++){
            for(int j = 1;j < m; j++){
                if(text1[i] != text2[j]) dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if(text1[i] == text2[j]) dp[i][j] = 1 + dp[i-1][j-1];
            }
        }

        return dp[n-1][m-1];
    }
};