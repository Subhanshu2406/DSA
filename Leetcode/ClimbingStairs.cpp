//one approach is to do dfs and the base case is if no steps are left then increase the counter and if steps become negative return but dont return counter. 
//this method is 2^n time complexity however and can result in TLE
class Solution {
    int counter = 0;
public:
    int climbStairs(int n) {
        climb(n);
        return counter;
    }
    void climb(int n){
        if(n < 0) return;
        else if (n == 0) {
            counter++; 
            return;
        }
        climb(n - 1);
        climb(n - 2);
        return;
    }
};

//using dp we can achieve a O(n) as we will be calculating from each step only once. 
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i < n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};