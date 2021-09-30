class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) { 
        auto compare = [&](const vector<int>& vec1, const vector<int>& vec2) {
                                    return vec1[0] < vec2[0];
                            };
        
        // Sort elements
        sort (intervals.begin(), intervals.end(), compare); 
        
        // Use priority queue for ending time comparision
        auto comparator = [&](int element1, int element2){ return element1 > element2; };
        priority_queue<int, vector<int>, decltype(comparator)> minHeap (comparator);
        
        for (auto interval : intervals)
        {
            if ((minHeap.size() > 0) && (minHeap.top() <= interval.at(0)))
                     minHeap.pop();
            minHeap.push(interval.at(1));
        }

        return minHeap.size();       
    }
};
