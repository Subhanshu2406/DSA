//O(n^2 solution)
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         for(int i = 0;i < nums.size(); i ++){
//             for(int j = 0;j < nums.size(); j ++){
//                 if(nums[i] == nums[j] && (i!=j)){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };


class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> data {};
            for(auto num : nums){
                auto it = data.find(num);
                if(it != data.end()){
                   return true; 
                }
                else{
                    data.insert(num);
                }
            }
            return false;
        }
    };


