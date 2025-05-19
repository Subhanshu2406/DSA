//my try using hashmaps but wont compile as time complexity is too much
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> answer{};
            int counter = 0;
            for(int i = 0 ; i < nums.size();i++)
            {
                int target = -nums[i];
                unordered_map<int,int> map {};
                for(int j = 0;j<nums.size() && j != i;j++){
                    int third = target - nums[j];
                    if(map.find(third) != map.end()) {
                        vector<int> temp = {nums[i],nums[j],third};
                        sort(temp.begin(), temp.end());
                        if(find(answer.begin(), answer.end(), temp) != answer.end()) continue;
                        answer.push_back(temp);
                    }
                    map[nums[j]] = j;
                }
            }
            return answer;
        }
    };


class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>> answer;
            for(int i=0;i<nums.size();i++){
    
                if(i> 0 && nums[i] == nums[i-1]) continue;
    
                int l = i+1;
                int r = nums.size() - 1;
    
                while(l<r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum == 0){
                        answer.push_back({nums[i],nums[l],nums[r]});
                        l++;
                        r--;
                        while(l<r && nums[l-1] == nums[l]){
                            l++;
                        }
                    }
    
                    else if(sum > 0) r--;
                    else if( sum < 0) l++;
                }
            }
    
            return answer;
        }
    };

