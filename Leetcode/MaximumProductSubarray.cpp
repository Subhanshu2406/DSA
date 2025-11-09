//brute force O(N^2) solution where we calculate for all subarrays
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = 1;
        int n = nums.size();
        for(int i = 0;i < n; i++){
            int temp = 1;
            for(int j = i;j < n;j++){
                temp = temp * nums[j];
                res = max(res,temp);
            }
        }
        return res;
    }
};

//we can use prefix suffix method to obtain a O(N) solution
//basically in an subarray with no zeros we have 3 cases:
//    1: all elements are postive so we return the product or subarray
//    2: even no of negatives so same as 1
//    3: if we have odd no of negatives, we would have to remove one negative number, the way we do this is by realising if we remove a negative number we either return its prefix or suffix product so we store the prefixes and suffixes and return the max of them
//so basically we have prefix and suffix product and for every number we choose the larger of prefix and suffix and update it with res
//in this code, technically we are actually comparing prefix and suffix of different indexes but its fine since in the end the res is anyways max of all possible prefixes and suffixes
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int res = INT_MIN;

        for (int i = 0; i < n; i++) {
            prefix = nums[i] * (prefix == 0 ? 1 : prefix);
            suffix = nums[n - 1 - i] * (suffix == 0 ? 1 : suffix);
            res = max(res, max(prefix, suffix));
        }
        return res;
    }
};