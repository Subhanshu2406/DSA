class Solution {
    public:
        int maxArea(vector<int>& height) {
    
            int l = 0 ;
            int r = height.size() - 1;
            int answer = 0;
            int temp;
    
            while(l<r){
                int length = min(height[l],height[r]);
                temp = (r-l)*(length);
                if(temp > answer) answer = temp;
    
                if(height[l] > height[r]) r--;
                else if(height[l] < height[r]) l++;
                else if(height[l] == height[r] && height[l+1] > height[r-1]) l++;
                else if(height[l] == height[r] && height[l+1] <= height[r-1]) r--;
            }
    
            return answer;
    
             
        }
    };