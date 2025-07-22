class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int counter = 0;
    bool full = false;
public:
    KthLargest(int k, vector<int>& nums) {
        for(auto num : nums){
            if(counter < k){
                minHeap.push(num);
                counter++;
            }
            else if(counter >= k && num > minHeap.top()){
                minHeap.pop();
                minHeap.push(num);
            }
        }

        if(counter == k) full = true;
    } //nlog(k) time 
    
    int add(int val) {
        if(!full){
            minHeap.push(val);
            full = true;  //since k <= num.length + 1 so the first time this occurs heap becomes full 
        }

        else if(full && val > minHeap.top()){
            minHeap.pop();
            minHeap.push(val);
        }

        return minHeap.top();
    }  //log(k) time
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */