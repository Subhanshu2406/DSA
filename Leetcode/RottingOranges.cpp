//basically we first take all rotten oragnes and run bfs on all of them , every bfs if we find a good orange we turn it rotten and push that orange into q which would do bfs next
//however in the end if we didnt turn all oranges into rotten we return -1
//one thing we need to keep in mind is in bfs we increase the days only if theres rotten oranges left as if theres no rotten oranges left in q that means the rotten oranges from previous days didnt turn any good oranges rotten so we dont count this day and return the prev day

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(); 
        int cols = grid[0].size();
        int freshOranges = 0;
        int days = 0;
        vector<vector<int>> isRotten(rows,vector<int>(cols,-1));
        queue<pair<int,int>> rotten;
        for(int i = 0;i < rows;i++){
            for(int j = 0;j  < cols;j++){
                if(grid[i][j] == 2){
                    rotten.push({i,j});
                    isRotten[i][j] = 1;
                }
                else if(grid[i][j] == 1) freshOranges++;
            }
        }

        if(rotten.empty() && freshOranges == 0) return 0;
        while(!rotten.empty()){
            int size = rotten.size();
            for(int i = 0;i < size;i ++){
                auto [r, c] = rotten.front();
                rotten.pop();
                if(r + 1 < rows && grid[r+1][c] == 1 && isRotten[r+1][c] == -1){
                    isRotten[r+1][c] = 1;
                    rotten.push({r+1,c});
                    freshOranges--;
                }
                if(r -1 >= 0 && grid[r-1][c] == 1 && isRotten[r-1][c] == -1){
                    isRotten[r-1][c] = 1;
                    rotten.push({r-1,c});
                    freshOranges--;
                }
                if(c + 1 < cols && grid[r][c+1] == 1 && isRotten[r][c+1] == -1){
                    isRotten[r][c+1] = 1;
                    rotten.push({r,c+1});
                    freshOranges--;
                }
                if(c - 1 >= 0 && grid[r][c - 1] == 1 && isRotten[r][c - 1] == -1){
                    isRotten[r][c - 1] = 1;
                    rotten.push({r,c - 1});
                    freshOranges--;
                }
            }
            if(!rotten.empty()) days++;  //this is false in the case of last day as no oranges were turned rotten
        }
        if(freshOranges != 0) return -1;
        return days;
    }
};