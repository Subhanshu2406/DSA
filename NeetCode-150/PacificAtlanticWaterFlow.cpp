//a dfs and use memoization wont work as say we went from a -> b where b is enclosed and cant go anywhere so we mark both a and b as visited and not able to reach the water but say if water was able to go from a -> b -> some c,d,e,sea which we never checked so a and b although possibly could reach the sea, we marked them as false.
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<pair<bool,bool>>> pacific(n,vector<pair<bool,bool>>(m,{false,false}));
        vector<vector<pair<bool,bool>>> atlantic(n,vector<pair<bool,bool>>(m,{false,false}));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;j ++){
                if(!pacific[i][j].second){
                    dfs(heights,pacific,i,j,0);
                }
                if(!atlantic[i][j].second){
                    dfs(heights,atlantic,i,j,1);
                }
            }
        }

        for(int i = 0;i < n ; i ++){
            for(int j = 0;j < m; j++){
                if(pacific[i][j].first && atlantic[i][j].first) res.push_back({i,j});
            }
        }
        return res;
    }

    bool dfs(vector<vector<int>>& heights, vector<vector<pair<bool,bool>>> &sea, int i, int j, int type){
        int n = heights.size();
        int m = heights[0].size();

        if(sea[i][j].second) return sea[i][j].first;
        sea[i][j].second = true;

        if(type == 0 && (i == 0 || j == 0)){
            sea[i][j].first = true;
            return sea[i][j].first;
        }
        else if(type == 1 && (i == n - 1|| j  == m - 1)){
            sea[i][j].first = true;
            return sea[i][j].first;
        }

        if(i + 1 < n && heights[i+1][j] <= heights[i][j] && dfs(heights,sea,i+1,j,type)) sea[i][j].first = true;
        if(j + 1 < m && heights[i][j+1] <= heights[i][j] &&  dfs(heights,sea,i,j+1,type)) sea[i][j].first = true;
        if(i - 1 >= 0 && heights[i-1][j] <= heights[i][j] &&  dfs(heights,sea,i-1,j,type)) sea[i][j].first = true;
        if(j - 1 >= 0 && heights[i][j-1] <= heights[i][j] &&  dfs(heights,sea,i,j-1,type)) sea[i][j].first = true;

        return sea[i][j].first;
    }
};