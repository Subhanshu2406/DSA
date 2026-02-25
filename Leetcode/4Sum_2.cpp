class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        sort(nums4.begin(), nums4.end());

        int res = 0;
        int n = nums1.size();

        for(int i = 0; i < n;i++){
            for(int j = 0;j < n;j++){

                int l = 0;
                int r = n-1;

                unordered_map<int,int> m1;
                unordered_map<int,int> m2;

                for(auto num : nums3){
                    m1[num]++;
                }

                for(auto num : nums4){
                    m2[num]++;
                }

                for(auto it = m1.begin(); it != m1.end(); it++){
                    int t = it -> first;

                    int target = -(nums1[i] + nums2[j] + t);
                    res += (it -> second * m2[target]);
                }

            }
        }
        return res;
    }
};




//trying another approach

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        int n = nums1.size();

        unordered_map<int,int> m1;
        unordered_map<int,int> m2;

        for(int i = 0; i< n;i++){
            for(int j = 0; j< n;j++){
                m1[nums1[i] + nums2[j]]++;
            }
        }

        for(int i = 0; i< n;i++){
            for(int j = 0; j< n;j++){
                m2[nums3[i] + nums4[j]]++;
            }
        }

        for(auto it : m1){
            res += (it.second * m2[-(it.first)]);
        }
        return res;
    }
};