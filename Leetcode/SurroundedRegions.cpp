class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    bool border = false;
                    vector<pair<int,int>> comp;
                    queue<pair<int,int>> q;

                    q.push({i,j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto [r,c] = q.front(); q.pop();
                        comp.push_back({r,c});
                        if (r==0 || r==n-1 || c==0 || c==m-1) border = true;

                        for (auto [dr,dc] : dirs) {
                            int nr = r+dr, nc = c+dc;
                            if (nr>=0 && nr<n && nc>=0 && nc<m &&
                                board[nr][nc]=='O' && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                q.push({nr,nc});
                            }
                        }
                    }

                    // Flip only if not touching border
                    if (!border) {
                        for (auto [r,c] : comp) board[r][c] = 'X';
                    }
                }
            }
        }
    }
};
