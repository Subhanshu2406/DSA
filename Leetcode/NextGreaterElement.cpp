class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> stk;

        for(int i = 0;i < nums2.size(); i++){
            while(!stk.empty() && nums2[i] > stk.top()){
                map[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }

        while(!stk.empty()){
            map[stk.top()] = -1;
            stk.pop();
        }

        vector<int> res;
        for(int i = 0;i < nums1.size();i++){
            res.push_back(map[nums1[i]]);
        }

        return res;
    }
};