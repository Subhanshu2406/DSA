class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }

        int newSlow = nums[0];
        while(true){
            if(newSlow == slow) return slow;
            newSlow = nums[newSlow];
            slow = nums[slow];
        }
        return 0;

    }
};