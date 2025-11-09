//we basically do bfs, where we start from first element and then check the ranges of all elements that we can reach from the first element
//the element which has the largest range would be our next move since we need to find element which can go furthest such that we have more possibilities which can lead to less no of steps
class Solution {
public:
    int jump(vector<int>& nums) {
        int index = 0;
        int res = 0;
        while(index < nums.size() - 1){
            int maxRange = index;
            int newIndex = index;
            for(int jumps = 1; jumps <= nums[index]; jumps++){
                if(index + jumps >= nums.size() - 1) return res + 1;   //bounds check
                if(index + jumps + nums[index + jumps] >= maxRange) {
                    maxRange = index + jumps + nums[index + jumps];
                    newIndex = index + jumps;
                }
            }
            res++;
            index = newIndex;
        }
        return res;        
    }
};