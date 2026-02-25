class MedianFinder {
public:
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
int n;
    MedianFinder() {
        n = 0;
        return;
    }
    
    void addNum(int num) {
        if(n == 0 || n == 1){
            maxHeap.push(num);
            if(maxHeap.size() == 2){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            n++;
            return;
        }

        int temp = num;
        if(num < maxHeap.top()){
            maxHeap.push(temp);
            temp = maxHeap.top();
            maxHeap.pop();
        }
        else if(num > minHeap.top()){
            minHeap.push(temp);
            temp = minHeap.top();
            minHeap.pop();
        }


        if(n % 2 == 0){
            maxHeap.push(temp);
        }
        else{
            minHeap.push(temp);
        }
        n++;
        return;
    }
    
    double findMedian() {
        if(n == 0) return 0;
        if(n == 1) return maxHeap.top();

        if(n % 2 == 0) return ((double)maxHeap.top() + minHeap.top()) / 2;
        else return maxHeap.top();
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */