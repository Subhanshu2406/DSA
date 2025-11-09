//My approach:
//We will do the usual back tracking, either we include a particular number or we dont
//Difference is, when we dont include a particular number we increase the index as usual to decide upon the next number
//If we do include a number, we will NOT increase the index, since that way next time we can decide if we again want to include the same number or not
//This continues till the sum of subset is less than target
//if it reaches target we add it to res vector, if it becomes more than the target, we backtrack.
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        int index = 0;
        int sum = 0;
        dfs(candidates,res,subset,index,sum,target);
        return res;
    }

    void dfs(vector<int>& candidates,vector<vector<int>>& res,vector<int>& subset,int index, int sum, int target){
        if(sum == target){
            res.push_back(subset);
            return;
        }
        else if(sum > target || index >= candidates.size()) return;

        subset.push_back(candidates[index]);
        dfs(candidates,res,subset,index,sum + candidates[index],target);
        subset.pop_back();
        dfs(candidates,res,subset,index + 1,sum,target);
    }
};