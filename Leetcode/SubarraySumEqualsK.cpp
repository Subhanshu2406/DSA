class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,vector<int>> map;
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        map[prefix[0]].push_back(0);

        for(int i = 1;i < n;i++){
            prefix[i] = prefix[i-1] + nums[i];
            map[prefix[i]].push_back(i);
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            int diff = prefix[i] - k;
            vector<int> temp = map[diff];
            for(auto num : temp){
                if(num < i) res++;
            }
        }

        res += map[k].size();

        return res;

    }
};



for optimized O(n):

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // prefix sum = 0 occurs once, HANDELS THE EDGE CASE

        int prefix = 0;
        int count = 0;

        for (int num : nums) {
            prefix += num;

            if (mp.find(prefix - k) != mp.end()) {
                count += mp[prefix - k];
            }

            mp[prefix]++;
        }

        return count;
    }
};