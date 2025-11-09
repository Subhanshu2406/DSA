class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        for(auto interval : intervals){
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(start.begin(),start.end());
        sort(end.begin(), end.end());

        int st = 0;
        int en = 0;

        int res = 0;
        int count = 0;
        while(st < intervals.size()){
            if(start[st] < end[en]){
                count ++;
                st++;
            }

            else{
                count --;
                en++;
            }

            res = max(res,count);
        }

        return res;
    }
};