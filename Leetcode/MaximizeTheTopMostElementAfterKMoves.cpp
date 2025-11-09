class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        int maxNum = INT_MIN;
        if(n == 1){
            if(k % 2 == 0) return nums[0];
            else return -1;
        }

        for(int i = 0;i < k-1;i++){
            if(i >= n) break;
            maxNum = max(nums[i],maxNum);
        }
        if(k < n && nums[k] > maxNum) return nums[k];
        return maxNum;
    }
};