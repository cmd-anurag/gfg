#include<vector>
#include<algorithm>

using std::vector, std::sort;

bool compare(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(), intervals.end(), compare);
        
        int lastValid = intervals[0][1];
        int count = 0;
        
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i][0] < lastValid) {
                ++count;
            }
            else {
                lastValid = intervals[i][1];
            }
            // cout << pair[1] << " ";
        }
        
        return count;
    }
    private:
};
