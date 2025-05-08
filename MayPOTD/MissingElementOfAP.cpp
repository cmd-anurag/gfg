#include <vector>
using std::vector;

class Solution {
    public:
      int findMissing(vector<int> &arr) {
         
          int n = arr.size() + 1;
          int a = arr[0];
          int d = std::min(arr[1] - arr[0], arr.back() - arr[arr.size() - 2]);
  
          int left = 0;
          int right = arr.size() - 1;
  
          while(left <= right) {
              int mid = left + (right - left) / 2;
              int expected = a + mid * d;
  
              if(arr[mid] == expected) {
                  left = mid + 1;
              }
              else {
                  right = mid - 1;
              }
          }
  
          return a + left * d;
      }
  };