// Min heap for earliest end times, most overlap will be heap size

// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto&b) {
            return a[0] < b[0];
        });
        
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
