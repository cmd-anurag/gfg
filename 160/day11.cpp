#include<vector>
#include<climits>
class Solution {
  public:
    int maxProduct(std::vector<int> &arr) {
        int startToEndProduct = 1;
        int endToStartProduct = 1;
        int answer = INT_MIN;
        
        int n = arr.size();
        
        for(int i = 0; i < n; ++i)
        {
            startToEndProduct *= arr[i];
            endToStartProduct *= arr[n-i-1];
            answer = std::max(answer, startToEndProduct);
            answer = std::max(answer, endToStartProduct);
            
            if(arr[i] == 0)
            {
                startToEndProduct = 1;
            }
            if(arr[n-i-1] == 0)
            {
                endToStartProduct = 1;
            }
        }
        
        return answer;
    }
};