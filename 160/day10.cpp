#include<vector>
#include<climits>

class Solution {
  public:
    int maxSubarraySum(std::vector<int> &arr) {
        // Code here
        int result = INT_MIN;
        int sum = 0;
        
        for(int x : arr)
        {
            sum += x;
            result = std::max(sum, result);
            if(sum < 0) sum = 0;
            
        }
        return result;
    }
};