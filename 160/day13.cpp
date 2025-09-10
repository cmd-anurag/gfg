#include<vector>

class Solution {
  public:
    int missingNumber(std::vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int i = 0;
        while(i < n)
        {
            if(arr[i] < 1 || arr[i] > n) // out of range
            {
                ++i;
                continue;
            }
            
            int correctIndex = arr[i] - 1;
            
            if(arr[i] == arr[correctIndex]) // already at correct index
            {
                ++i;
                continue;
            }
            
            
            swap(arr[i], arr[correctIndex]);
        }
        
        for(int i = 0; i < n; ++i)
        {
            if(arr[i] != i+1) return i+1;
        }
    }
  private:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};