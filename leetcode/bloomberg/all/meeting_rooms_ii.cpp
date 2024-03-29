/*
    Given array of time intervals, determine min # of meeting rooms required
    Ex. intervals = [[0,30],[5,10],[15,20]] -> 2

    Min heap for earliest end times, most overlap will be heap size

    Time: O(n log n)
    Space: O(n)
*/

// class Solution {
// public:
//     int minMeetingRooms(vector<vector<int>>& intervals) {
//         // {time -> val (+1 if start, -1 if end)}
//         map<int, int> m;
//         for (int i = 0; i < intervals.size(); i++) {
//             m[intervals[i][0]]++;
//             m[intervals[i][1]]--;
//         }
//         int count = 0;
//         int result = 0;
//         for (auto it = m.begin(); it != m.end(); it++) {
//             count += it->second;
//             result = max(result, count);
//         }
//         return result;
//     }
// };

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort intervals by start time
        sort(intervals.begin(), intervals.end());
        
        // min heap to track min end time of merged intervals
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        
        for (int i = 1; i < intervals.size(); i++) {
            // compare curr start w/ earliest end time, if no overlap then pop
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            // add new room (will replace/be same size if above was true)
            pq.push(intervals[i][1]);
        }
        
        return pq.size();
    }
};
