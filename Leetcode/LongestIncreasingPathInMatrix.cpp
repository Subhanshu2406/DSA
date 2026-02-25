class Solution {
public:
    vector<vector<int>> memo;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memo.resize(n, vector<int>(m, -1));
        int res = 0;

        for(int i = 0;i < n; i++){
            for(int j = 0;j < m;j++){
                if(memo[i][j] == -1) dfs(i, j, matrix);
                res = max(res, memo[i][j]);
            }
        }

        return res;
    }

    int dfs(int i, int j, vector<vector<int>>& matrix){

        int n = matrix.size();
        int m = matrix[0].size();

        if(memo[i][j] != -1) return memo[i][j];
        memo[i][j] = 1;

        vector<vector<int>> diff = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        for(auto d : diff){
            int dx = d[0];
            int dy = d[1];

            if(i + dx < n && i + dx >= 0 && j + dy < m && j + dy >= 0 && matrix[i+dx][j+dy] > matrix[i][j]){
                memo[i][j] = max(memo[i][j], dfs(i + dx, j + dy, matrix) + 1);
            } 
        }

        return memo[i][j];
    }
};