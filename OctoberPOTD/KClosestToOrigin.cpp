#include<vector>
#include<queue>
using std::priority_queue, std::vector, std::pair, std::greater;

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minheap;
        
        for(int i = 0; i < points.size(); ++i) {
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            
            minheap.push({distance, i});
        }
        
        // while(!minheap.empty()) {
        //     cout << minheap.top().first << "->" << minheap.top().second << " ";
        //     minheap.pop();
        // }
        
        vector<vector<int>> result;
        for(int i = 0; i < k; ++i) {
            auto pair = minheap.top();
            minheap.pop();
            result.push_back(points[pair.second]);
        }
        
        return result;
    }
};