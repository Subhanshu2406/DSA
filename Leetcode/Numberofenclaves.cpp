class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        int res = 0;


        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = true;
                    bool flag = true;
                    int temp = 0;

                    while(!q.empty()){
                        temp ++;
                        pair<int,int> p = q.front();
                        q.pop();

                        vector<vector<int>> diff {{0,1}, {1,0}, {-1,0}, {0,-1}};
                        for(auto d : diff){
                            int r = p.first + d[0];
                            int c = p.second + d[1];

                            if(r >= n || r < 0 || c < 0 || c >= m) flag = false;
                            else if(r < n && r >= 0 && c < m && c >= 0 && grid[r][c] == 1 && !visited[r][c]) {
                                q.push({r,c});
                                visited[r][c] = true;
                            }
                        }

                    }

                    if(flag) res += temp;
                }
            }
        }

        return res;

    }
};