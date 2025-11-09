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