class Solution {
public:
    static bool logic(pair<int,int> a, pair<int,int> b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> sorted(n);

        for (int i = 0; i < n; ++i) {
            sorted[i] = {position[i], speed[i]};
        }

        sort(sorted.begin(), sorted.end(), logic);

        vector<float> time_taken(n);

        for (int i = 0; i < n; ++i) {
            time_taken[i] = (float)(target - sorted[i].first) / sorted[i].second;
        }

        int fleet = 0;
        float curr_max_time = 0;

        for (float t : time_taken) {
            if (t > curr_max_time) {
                fleet++;
                curr_max_time = t;
            }
        }

        return fleet;
    }
};
class Solution {
public:
    static bool logic(pair<int,int> a, pair<int,int> b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> sorted(n);

        for (int i = 0; i < n; ++i) {
            sorted[i] = {position[i], speed[i]};
        }

        sort(sorted.begin(), sorted.end(), logic);

        vector<float> time_taken(n);

        for (int i = 0; i < n; ++i) {
            time_taken[i] = (float)(target - sorted[i].first) / sorted[i].second;
        }

        int fleet = 0;
        float curr_max_time = 0;

        for (float t : time_taken) {
            if (t > curr_max_time) {
                fleet++;
                curr_max_time = t;
            }
        }

        return fleet;
    }
};
