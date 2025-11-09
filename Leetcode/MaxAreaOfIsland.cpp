class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int res = 0;
        vector<vector<int>> seen(rows,vector<int>(columns,-1)); 
        for(int i = 0;i < rows;i ++){
            for(int j = 0;j < columns;j++){
                if(grid[i][j] == 1 && seen[i][j] == -1) res = max(res,dfs(grid,seen,i,j));
            }
        }     
        return res;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& seen,int i, int j){
        if(grid.size() <= i || i < 0 || grid[0].size() <= j || j < 0 || seen[i][j] == 1 || grid[i][j] == 0) return 0;

        seen[i][j] = 1;
        return 1 + dfs(grid,seen,i+1,j) + dfs(grid,seen,i-1,j) + dfs(grid,seen,i,j+1) + dfs(grid,seen,i,j-1);
    }
};