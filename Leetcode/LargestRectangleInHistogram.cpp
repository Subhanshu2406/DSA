class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int max = 0;
        while(l <= r){
            int area = (r - l + 1)*min_element( heights.begin()+l,heights.end() + r + 1);
            if(area > max) max = area;
            if(heights[l] > heights[r]) r--;
            else l++;
        }
        return max;
    }
};