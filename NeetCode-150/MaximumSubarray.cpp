//we interate through array, keeping an variable sum to which we keep adding the present element. If sum becomes negative we set it to zero since any subarray after this will be greater if we dont consider the subarray till now
//also called kadanes algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;
        for(int num : nums){
            sum += num;
            res = max(res,sum);
            if(sum < 0) sum = 0;
        }
        return res;
    }
};