//approach: we can make a min heap, and fill it with k elements first. Now upon additional elements we first push the additional element one time and pop the minimum element, this way technically we are preserving the k largest elements in the min heap

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater> pq;
        for(auto num : nums){
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};