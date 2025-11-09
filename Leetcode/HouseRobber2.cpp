//this is basically house robber 1 but we if first and last houses are adjacent aswell
//So since houses are circular in place, one way to deal with it is lets first calculate answer without last house then without first house and return max of those
//the reason this works is in first case when we remove the last house, we basically make it a straight line(house robber 1) and calculate the ans but the actual answer might involve us robbing the last house but in that case we are sure we wont rob first house so we run dp again but without first house 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        if(n == 0) return nums[0];
        if(n == 1) return max(nums[0],nums[1]);
        vector<int> dp1(n);
        vector<int> dp2(n);

        dp1[0] = nums[0];
        dp1[1] = max(nums[1],nums[0]);
        for(int i = 2;i < n ; i++){
            dp1[i] = max(dp1[i-1],dp1[i-2] + nums[i]);
        }

        nums.erase(nums.begin());
        dp2[0] = nums[0];
        dp2[1] = max(nums[1],nums[0]);
        for(int i = 2;i < n ; i++){
            dp2[i] = max(dp2[i-1],dp2[i-2] + nums[i]);
        }

        return max(dp1[n-1],dp2[n-1]);
    }
};