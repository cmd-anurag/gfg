#include<vector>
#include<algorithm>

class Solution {
  public:
    int getMinDiff(std::vector<int> &arr, int k) {
        
        int n = arr.size();
        
        std::sort(arr.begin(), arr.end());
        
        int answer = arr[n-1] - arr[0];
        
        for(int i = 0; i < n; ++i)
        {
            if(arr[i] - k < 0) continue;
            
            int minHeight = std::min(arr[0] + k, arr[i] - k);
            int maxHeight = std::max(arr[i-1] + k, arr[n-1] - k);
            
            answer =std::min(answer, maxHeight - minHeight);
        }
        
        return answer;
    }
};