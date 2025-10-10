//here we do dfs for both oceans for both borders
//we start from borders as obvio we can reach ocean from borders and then see which cells adjacent to border can reach border and mark them true and then continue this in dfs fashion
//we dont even need a visited list here since, if a cell was earlier marked true then it means water can reach border from that cell to ocean so dfs was already performed on it
//however say if a cell is marked false, it means till now we havent found an way for this cell to reach border, so we check height with curr cell and see if this adjacent cell can reach curr cell coz if it can then it reaches the border

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));

        for(int i = 0;i < n;i ++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m-1);
        }

        for(int i = 0; i < m;i ++){
            dfs(heights,pacific,0,i);
            dfs(heights,atlantic,n-1,i);
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }

        return res;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &sea, int row, int col){
        sea[row][col] = true;
        vector<pair<int,int>> diff = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int j = 0;j < 4; j++){
            int newRow = row + diff[j].first;
            int newCol = col + diff[j].second;
            if(newRow < heights.size() && newRow >= 0 && newCol < heights[0].size() && newCol >= 0 && !sea[newRow][newCol] && heights[newRow][newCol] >= heights[row][col]) dfs(heights,sea,newRow,newCol);
        }
    }
};