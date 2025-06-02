//brute for solution for O(n*maxheight) which can be sometimes as good as O(n) or sometimes worse than O(n^2).

class Solution {
public:
    int trap(vector<int>& height) {
        int max_height = *max_element(height.begin(),height.end());
        vector<int> water(max_height+1,0);
        for(int i = 1;i <= max_height;i++){
            int l = 0;
            int r = height.size() - 1;
            int start = -1;
            int end = -1;
            while(start == -1){
                    if(height[l] >= i && start == -1) start = l;
                    else l++;
            }
                    
            while(end == -1){
                if(height[r] >= i && end == -1) end = r;
                else r--;
            }

            if(start == end) continue;
            for(int j = 0;j<height.size();j++){
                if(j <= start || j >= end) continue;
                if(height[j] < i) water[i]++;
            }

        }

        int answer = 0;

        for(int i = 0;i<max_height+1;i++){
                answer += water[i];
        }

        return answer;
    }
};


//O(n) solution using two pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;

        int water = 0;
        int rmax = height[r];
        int lmax = height[l];

        while(l <= r){
            if(lmax >= rmax){
                int temp= min(lmax,rmax) - height[r--];
                if(height[r] > rmax) rmax = height[r];
                if(temp > 0) water += temp;  
            }

            else if(lmax < rmax){
                int temp= min(lmax,rmax) - height[l++];
                if(height[l] > lmax) lmax = height[l];
                if(temp > 0) water += temp;  
            }
        }

        return water;
    }
};