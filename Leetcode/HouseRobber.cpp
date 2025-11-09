//this is a bad implementation of dp and the reoccurence relation is not ideal but this works although its not strict dp since if there are n houses we dont return dp[n-1] but rather an counter which keeps track of max money appeared so far
//Basically in this at a particular house we calculate what if i will get max by stealing this house , we either hop from i-2 to this house or i -3 , not i-4 or prior coz we can hop houses in middle and then hop at this ith house 
//so here dp[n] wont actually be the best way to rob but rather the highest i can make if i rob the nth house aswell, this is why we use a temp variable money 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> dp(n);
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + dp[0];
        int money = max(dp[1],dp[2]);
        for(int i = 3; i < n;i++){
            dp[i] = nums[i] + max(dp[i-2],dp[i-3]);
            money = max(money,dp[i]);
        }
        return money;
    }
};