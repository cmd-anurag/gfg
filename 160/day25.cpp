#include<vector>
using std::max, std::vector;

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<vector<int>> result;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int n = intervals.size();
        
        int i = 0;
        
        while(i < n && newStart >= intervals[i][0]) {
            result.push_back({intervals[i][0], intervals[i][1]});
            ++i;
        }
        
        
        if(!result.empty() &&newStart <= result.back().at(1)) {
            result.back().at(1) = max(newEnd, result.back().at(1));
        }
        else {
            result.push_back({newStart, newEnd});
        }
        
        while(i < n && intervals[i][0] <= result.back().at(1)) {
            result.back().at(1) = max(result.back().at(1), intervals[i][1]);
            ++i;
        }
        
        while(i < n)
        {
            result.push_back({intervals[i][0], intervals[i][1]});
            ++i;
        }
        
        return result;
    }
};