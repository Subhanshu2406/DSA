#include <bits/stdc++.h>
using namespace std;

struct compare {
    bool operator()(const pair<int, pair<int, int>>& a,
                    const pair<int, pair<int, int>>& b) const {
        return a.second.second > b.second.second;
    }
};

class MeetingScheduler {
private:
    int n; // number of rooms
    vector<vector<int>> meetings;
    vector<int> freq;

public:
    MeetingScheduler(int numRooms, vector<vector<int>>& meet) {
        n = numRooms;
        meetings = meet;
        freq.resize(numRooms, 0);
    }

    int mostBooked() {
        // TODO: Implement the logic to find the most booked room
        // Hints:
        // 1. Use min-heap for available rooms
        // 2. Use min-heap for occupied rooms with end times
        // 3. Sort meetings by start time
        // 4. Track count of meetings per room

        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] < b[0]) return true;
            else if(a[0] > b[0]) return false;
            else{
                return a[1] < b[1];
            }
        });

        priority_queue<int,vector<int>,greater<int>> available;
        for(int i = 0;i < n; i++) available.push(i);

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, compare> booked;


        for(auto meets : meetings){
            int startTime = meets[0];
            int endTime = meets[1];

            while(!booked.empty() && booked.top().second.second <= startTime) {
                auto p = booked.top();
                booked.pop();
                available.push(p.first);
            }

            if(!available.empty()){
                booked.push({available.top(),{startTime,endTime}});
                freq[available.top()]++;
                available.pop();
            }
            else {
                int newStart = booked.top().second.second;
                int diff = newStart - startTime;
                startTime += diff;
                endTime += diff;
                int room = booked.top().first;
                freq[room] ++;
                booked.pop();
                booked.push({room,{startTime,endTime}});
            }

        }
        int room = 0;
        int maxMeetings = 0;
        for(int i = 0;i < n; i++){
            if(freq[i] > maxMeetings){
                maxMeetings = freq[i];
                room = i;
            }
        }
        return room; // placeholder
    }
};

int main() {
    int n, m;
    cin >> n >> m; // number of rooms and number of meetings

    vector<vector<int>> meetings(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> meetings[i][0] >> meetings[i][1]; // start and end times
    }

    MeetingScheduler scheduler(n, meetings);

    cout << scheduler.mostBooked() << endl;

    return 0;
}