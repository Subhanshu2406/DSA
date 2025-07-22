//we solve using a max heap, we create a max heap and insert k distances along with its indexes into it first. Now upon adding additional distances we insert the distance and remove the max from heap such that we still ahve only k elements in the heap. This way we get the k elements with least distance from origin.

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int size = points.size();
        vector<pair<int,int>> vec(size,{0,0});
        priority_queue<pair<int,int>> pq; 

        for(int i = 0;i < size ; i++){
            vec[i].first = pow(points[i][0],2) + pow(points[i][1],2);
            vec[i].second = i;
            pq.push({vec[i].first,vec[i].second});  //logk time
            if(pq.size() > k) pq.pop();             //logk time
        }
        vector<vector<int>> res;
        while(pq.size()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};