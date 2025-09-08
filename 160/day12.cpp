#include<vector>
#include<climits>


class Solution {
  public:
    int maxCircularSum(std::vector<int> &arr) {
        // code here
        int totalSum = 0;
        
        int currentMaxSum = 0;
        int currentMinSum = 0;
        
        int maxSumAnswer = INT_MIN;
        int minSumAnswer = INT_MAX;
        
        for(int x : arr)
        {
            totalSum += x;
            
            currentMaxSum += x;
            currentMaxSum = std::max(currentMaxSum, x);
            maxSumAnswer = std::max(maxSumAnswer, currentMaxSum);
            
            currentMinSum += x;
            currentMinSum = std::min(currentMinSum, x);
            minSumAnswer = std::min(minSumAnswer, currentMinSum);
        }
        
        int normalSum = maxSumAnswer;
        int circularSum = totalSum - minSumAnswer;
        
        if(minSumAnswer == totalSum) return normalSum;
        
        
        
        return std::max(circularSum, normalSum);
    }
};