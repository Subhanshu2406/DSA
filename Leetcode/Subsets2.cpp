//My approach: 
//so this question is quite similar to subsets 1 lc question, where all nums were distinct so we would just backtrack and using decision trees decide if a number on the current index should be included or not following which we can generate all possible subsets. 
//in this question since we can have duplicate nums we will generate duplicate subsets following the above method, so to avoid that we will first sort the nums array (nlogn which is insignificant when compared to n * 2^n backtracking time complexity) , now if a number is repeated say for eg 1 2 2 2 3, we will draw the normal decision tree for 1(include or not to include) then for the 1st 2 we will again have 2 choices to include or not, now in the decision path where we DONT choose the 1st 2 to include we will move the index till it is no longer at 2.
//We do this because when we include the 1st 2 , we will generate all possibilites including atleast one 2 so when we have the choice to include the next 2s we dont do that as that will already have been covered in possibilities of when we include the 1st 2
//Basically in this for decision trees we either do yes and index + 1 or no and index + k till the new index is pointing to a new integer
//In basically for all combinations of 2 we can we sure that if we dont include a 2 at a certain index, we wouldnt want any 2nd folllowing that simply because those cases would anyways be included the yes case for that index, we only decide if we want to add another 2 or not
//Summarizing , say we have k 2s now order doesnt matter all we know is we can either have one 2 or two 2 or three 2 ... k two so say we are at index 5(meaning we are deciding the 5th 2 as of now from the k 2s) we either do yes and increase the index by 1(that means we want possibilites with atleast 5 2s) to get all possibilites of atleast 5 2s or do no and keep doing no to get that many exact 5 of 2s(since if we did no that means we do not want any more 2s or to "lock" that option we keep doing no till we reach a new number)  
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index = 0;
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums,res,subset,index);
        return res;
    }

    void dfs(vector<int> &nums,vector<vector<int>>& res, vector<int>& subset, int index){
        if(index >= nums.size()){
            res.push_back(subset);
            return;
        }
        int currInt = nums[index];
        int newIndex = index;
        subset.push_back(nums[index]);
        dfs(nums,res,subset,index + 1);
        subset.pop_back();
        while(nums.size() > newIndex && nums[newIndex] == currInt) newIndex ++;
        dfs(nums,res,subset,newIndex);
        return;
    }
};