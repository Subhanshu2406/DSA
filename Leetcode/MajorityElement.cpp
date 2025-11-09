class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int counter = 0;
        for(auto num : nums){
            if(num[i] == candidate) counter++;
            else{
                counter--;
                if(counter == 0){
                    candidate = nums[i];
                    counter++;
                }
            }
        }
    }
    return candidate;
};

//reason this works is basically ,the non majority elements despite how frequenctly they occur will always end with thier counter being less than 0 at the end since theres a majority element which would result in a mismatch
//so basically non majority in the end will end thier counters to be 0 and majority counter would be atleast 1