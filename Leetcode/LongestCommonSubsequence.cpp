//recursive memoized solution
class Solution {
public:
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.size(), vector<int>(text2.size(), -1));
        return dfs(text1 , text2, 0, 0);
    }

    int dfs(string s1, string s2, int first, int second){
        if(first >= s1.size() || second >= s2.size()) return 0;

        if(memo[first][second] != -1) return memo[first][second];

        if(s1[first] == s2[second]) memo[first][second] = 1 + dfs(s1, s2, first + 1, second + 1);   //if both match then it will always be more optimal to consider the present character
        else {
            memo[first][second] = max(dfs(s1,s2,first,second + 1), dfs(s1,s2,first+1,second));
        }

        return memo[first][second];
    }
};


//iterative dp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));

        int first = 0;
        int second = 0;

        for(int i = 0; i < text1.size(); i++){
            for(int j = 0; j < text2.size(); j++){
                if(text1[i] == text2[j]) 
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
};