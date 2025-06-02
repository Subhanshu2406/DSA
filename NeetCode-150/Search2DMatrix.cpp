class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix[0].size();
        int l = 0 ;
        int r = matrix.size() * rowSize - 1;
        while(l <= r){
            int mid = (l + r)/2;
            int i = mid / rowSize;
            int j = mid % rowSize;
            
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) r = mid - 1;
            else l = mid + 1;
        }
        
        return false;
    }
};