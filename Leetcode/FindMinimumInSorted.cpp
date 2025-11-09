class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        if(nums[l] < nums[r]) return 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(l == r) return mid;
            else if(r-l == 1){
                if(nums[l] > nums[r]) return r;
                else return l;
            }
            else if(nums[mid] < nums[l]) r = mid;
            else if(nums[mid] > nums[r]) l = mid;
            else return 0;
        }
        return 0;
    }
};