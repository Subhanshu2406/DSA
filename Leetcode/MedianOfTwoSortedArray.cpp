//This is O(n) solution
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = 0;
        int b = 0;
        int size = nums1.size()+nums2.size();
        vector<int> nums3(size);
        for(int i = 0;i<size;i++){
            if(nums1[a] >= nums2[b] && b < nums2.size()){
                nums3[i] = nums2[b];
                b++;
            }
            else if(nums1[a] < nums2[b] && a < nums1.size()){
                nums3[i] = nums1[a];
                a++;
            }
        }

        double median;
        if(nums3.size() % 2 == 0) median = (nums3[size/2] + nums3[size/2 - 1])/2.0;
        else median = nums3[size/2];

        return median;
    }
};


//This is the O(logn + logm) solution using binary search & divide and conquer
class Solution {
public:

    double find(int i, int j, int k, vector<int>& nums1, vector<int>& nums2){
        if(i >= nums1.size()) return nums2[j + k - 1];
        else if(j >= nums2.size()) return nums1[i + k - 1];
        else if(k == 1) return min(nums1[i], nums2[j]);

        //trick to check out of bounds when one array doesnt have enough elements to eliminate
        int midVal1 = INT_MAX;
        int midVal2 = INT_MAX;

        if (i + k/2 - 1 < nums1.size())         
            midVal1 = nums1[i + k/2 - 1];

        if (j + k/2 - 1 < nums2.size())
            midVal2 = nums2[j + k/2 - 1];

        if (midVal1 < midVal2)
            return find(i + k/2, j, k - k/2, nums1, nums2);
        else
            return find(i, j + k/2, k - k/2, nums1, nums2);
        return 0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int k1 = (n + m + 1) / 2;
        int k2 = (n + m + 2) / 2;

        return (find(0, 0, k1, nums1, nums2) + find(0, 0, k2, nums1, nums2) )/ 2;
    }

};