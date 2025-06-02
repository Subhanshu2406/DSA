class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            int noofRows = board[0].size();
            for(int i = 0;i<noofRows;i++){
                unordered_set<char> setRow = {};
                unordered_set<char> setColumn = {};
                for(int j = 0;j<noofRows;j++){
                    if(!setRow.insert(board[i][j]).second && board[i][j] != '.') return false;
                    if(!setColumn.insert(board[j][i]).second && board[j][i] != '.') return false;
                }
            }
            for(int n=0;n<7;n += 3){
                for(int m=0;m<7;m+=3){
                    unordered_set<char> setBox = {};
                    for(int i = 0;i<3;i++){
                        for(int j = 0;j<3;j++){
                            if(!setBox.insert(board[i+n][j+m]).second && board[i+n][j+m] != '.') return false;
                        }
                    }
                }
            }

            return true;


        }
    };