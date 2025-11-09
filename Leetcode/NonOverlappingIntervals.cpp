class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(!intervals.size()) return 0;
        vector<pair<int,int>> vec;
        for(int i = 0;i < intervals.size();i++){
            vec.push_back({intervals[i][0],intervals[i][1]});
        }

        sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });

        int res = 1;
        int endTime = vec[0].second;

        for(int i = 1;i < vec.size(); i++){
            if(endTime <= vec[i].first){
                res++;
                endTime = vec[i].second;
            }
        }

        return intervals.size() - res;
    }

};