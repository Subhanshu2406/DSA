class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;

            if(nums[mid] == target) return mid;

            //if mid in left sorted half
            else if(nums[mid] >= nums[l]){
                if(nums[mid] > target && nums[l] <= target){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }

            //if mid is in the right sorted half
            else if(nums[mid] <= nums[r]){
                if(nums[mid] < target && nums[r] >= target){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};