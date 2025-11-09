class Solution {
public:
int rows;
int columns;
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        columns = grid[0].size();
        int islands = 0;
        vector<vector<int>> seen(rows,vector<int>(columns,-1));
        for(int i = 0;i < rows; i++){
            for(int j = 0;j < columns; j++){
                if(seen[i][j] == -1 && grid[i][j] == '1'){
                    islands++;
                    dfs(grid,seen,i,j);
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>>& grid,vector<vector<int>>& seen,int i, int j){
        if(i < 0 || j < 0 || i >= rows || j >= columns || grid[i][j] == '0'|| seen[i][j] == 1) return;  //HERE ALSO seen == 1 because if we dont do this then say theres a square of 1s, we start at left top and the from dfs come to right top the right botton the left botton but then we will go to left top again from left bottom leading to infinite recursive call
        seen[i][j] = 1;
        dfs(grid,seen,i+1,j);
        dfs(grid,seen,i-1,j);
        dfs(grid,seen,i,j+1);
        dfs(grid,seen,i,j-1);
    }
    
    
};