class Solution {
public:
vector<vector<bool>> visited;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        visited.resize(n, vector<bool>(m,false));

        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = true;
        int start = image[sr][sc];
        image[sr][sc] = color;

        while(!q.empty()){
            int iterations = q.size();

            for(int i = 0; i < iterations ; i++){
                pair<int,int> p = q.front();
                q.pop();

                vector<vector<int>> diff {{1,0}, {-1,0}, {0,1}, {0,-1}};

                for(auto d : diff){
                    int r = p.first + d[0];
                    int c = p.second + d[1];

                    if(r < n && r >= 0 && c < m && c >= 0 && !visited[r][c] && image[r][c] == start){
                        q.push({r,c});
                        image[r][c] = color;
                        visited[r][c] = true;
                    }
                }
            }
        }

        return image;
    }
};