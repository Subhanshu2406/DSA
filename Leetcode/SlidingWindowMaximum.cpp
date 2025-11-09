class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int l = 0;
        int r = k - 1;
        int max = INT_MIN;
        unordered_map<int,int> map;
        for(int i = 0;i < k;i++){
            map[nums[i]]++;
            max = max(max,nums[i]);
        }

        while(r < nums.size()){
            l++;
            r++;
            map[nums[l]--];
            map[nums[r]++];
        }
    }
};