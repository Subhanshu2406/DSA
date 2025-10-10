class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        int start = newInterval[0];
        int end = newInterval[1];

        int startIndex = -1;  //stores the first overlapping index
        int endIndex = -1;    //stores the last overlapping index

        int i = 0;
        while(i < intervals.size()){
            if(intervals[i][1] >= start && intervals[i][0] <= end){
                startIndex = i;
                while(i < intervals.size() && (intervals[i][1] >= start && intervals[i][0] <= end)){
                    start = min(start, intervals[i][0]);
                    end = max(end, intervals[i][1]);
                    i++;
                }
                endIndex = i - 1;   //if we have a startIndex then at minimum we will have endIndex = startIndex
                break;
            }
            i++;
        }

        if(startIndex == -1 || endIndex == -1){
            //no overlapping intervals so just insert new interval and return
            bool inserted = false;
            for(int i = 0; i < intervals.size(); i++){
                if(intervals[i][0] > newInterval[0]) {
                    intervals.insert(intervals.begin() + i,newInterval);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) intervals.push_back(newInterval);
            return intervals;
        }

        for(int i = 0;i < startIndex; i++){     //intervals before overlapping interval
            res.push_back(intervals[i]);
        }

        //overlapping interval
        int overlappingStart = newInterval[0];
        int overlappingEnd = newInterval[1];

        for(int i = startIndex; i < endIndex + 1; i++){
            overlappingStart = min(overlappingStart, intervals[i][0]);
            overlappingEnd = max(overlappingEnd, intervals[i][1]);
        }
        
        res.push_back({overlappingStart, overlappingEnd});

        for(int i = endIndex + 1; i < intervals.size() ; i++){      //after overlapping interval
            res.push_back(intervals[i]);
        }

        return res;

    }
};