class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int index = 0;
        backtrack(nums,index);
        return res;
    }

    void backtrack(vector<int>& nums, int index){
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = index;i < nums.size();i++){
            swap(nums[index],nums[i]);
            backtrack(nums,index + 1);
            swap(nums[index],nums[i]);
        }
        return;
    }
};