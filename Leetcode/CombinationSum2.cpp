//My approach:
//So we do the usual backtracking(the one with the duplicates btw), but we only push those subsets to res which sum up to target

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int index = 0;
        vector<vector<int>> res;
        vector<int> subset;
        dfs(candidates,res,subset,index,target);
        return res;
    }

    void dfs(vector<int>& candidates,vector<vector<int>>& res,vector<int>& subset, int index, int target){
        if(index >= candidates.size()){
            if(accumulate(subset.begin(),subset.end(),0) == target) res.push_back(subset);
            return;
        }
        else if(accumulate(subset.begin(),subset.end(),0) > target) return;
        int curr = candidates[index];
        subset.push_back(candidates[index]);
        dfs(candidates,res,subset,index + 1,target);
        subset.pop_back();
        while(index < candidates.size() && curr == candidates[index]) index++;
        dfs(candidates,res,subset,index,target);
        return;
    }
};