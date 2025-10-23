#include<queue>
#include<vector>
#include<unordered_map>
using std::unordered_map, std::priority_queue, std::vector, std::pair;

class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int, int> hashmap;
        
        for(int i : arr) {
            hashmap[i]++;
        }
        priority_queue<pair<int, int>> maxh;
        
        for(const auto& pair: hashmap) {
            maxh.push({pair.second, pair.first});   
        }
        vector<int> result;
        
        int count = 0;
        while(!maxh.empty() && count<k) {
            result.push_back(maxh.top().second);
            maxh.pop();
            ++count;
        }
        
        return result;
    }
};
