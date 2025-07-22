class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end()); // nlogn time

        while(pq.size() > 1){
            int stone1 = pq.top();
            pq.pop(); //logn time
            int stone2 = pq.top();
            pq.pop();
            if(stone1 == stone2) continue;
            else{
                pq.push(stone1 - stone2); //logn time
            }
        } //each while loop takes logn time

        if(pq.size() == 0) return 0;
        return pq.top();


    }
};

//so time complexity is nlogn + nlogn => O(n) = nlogn