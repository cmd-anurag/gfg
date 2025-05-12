#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        
        sort(meetings.begin(), meetings.end());

        // Min-heap for free rooms (by room number)
        priority_queue<int, vector<int>, greater<int>> free_rooms;
        for (int i = 0; i < n; ++i) {
            free_rooms.push(i);
        }

        // Min-heap for occupied rooms: (end_time, room_number)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> ongoing;

        
        vector<int> count(n, 0);

        for (auto &meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];

            // free up rooms where meetings have ended
            while (!ongoing.empty() && ongoing.top().first <= start) {
                int room = ongoing.top().second;
                ongoing.pop();
                free_rooms.push(room);
            }

            if (!free_rooms.empty()) {
                int room = free_rooms.top();
                free_rooms.pop();
                ongoing.push({end, room});
                count[room]++;
            } else {
                // no room is free; delay the meeting
                pair<int, int> x  = ongoing.top();
                int avail_time = x.first;
                int room = x.second;
                
                ongoing.pop();
                long long duration = end - start;
                ongoing.push({avail_time + duration, room});
                count[room]++;
            }
        }

        
        int max_meetings = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > max_meetings) {
                max_meetings = count[i];
                result = i;
            }
        }

        return result;
    }
};
