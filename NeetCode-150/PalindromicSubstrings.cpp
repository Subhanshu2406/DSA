class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i = n-1;i >= 0; i--){
            for(int j = i; j < n; j ++){
                int l = i;
                int r = j;
                if(s[i] == s[j] && (r - l + 1 <= 2 || dp[i+1][j-1])){
                    res++;
                    dp[i][j] = true;
                }  
            }
        }

        return res;
    }
};