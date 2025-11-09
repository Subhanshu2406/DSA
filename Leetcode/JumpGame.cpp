//this is the memo + dp method to solve it in O(n^2) time complexity
class Solution {
    vector<pair<bool,bool>> memo;
public:
    bool canJump(vector<int>& nums) {
        memo.resize(nums.size(),{false,false});
        return dfs(nums,0);
    }

    bool dfs(vector<int>& nums,int index){
        if(index == nums.size() - 1) return true; 
        if(index > nums.size() - 1) memo[index].second = true;
        int jumps = nums[index];
        if(memo[index].second) return memo[index].first;

        for(int i = 1;i <= jumps;i ++){
            bool cond = dfs(nums,index + i);
            if(i + index < nums.size() && cond) return true;
        }
        memo[index].second = true;
        memo[index].first = false;
        return false;
    }
};

//using bottom up dp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> arr(nums.size());
        if(nums.size() < 2) return true;
        for(int i = nums.size() - 2;i >= 0; i--){
            int jumps = nums[i];
            if(i + jumps >= nums.size() - 1) {
                arr[i] = true; 
                continue;
            }
            for(int j = 1;j <= jumps ; j++){
                if(arr[i+j] == true){
                    arr[i] = true; 
                    break;
                }
            }
        }
        return arr[0];
    }
};


//greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums[nums.size() - 1];
        for(int i = nums.size() - 1; i >= 0 ; i--){
            if(nums[i] + i >= goal) goal = i;
        }
        return goal == 0;
    }
};