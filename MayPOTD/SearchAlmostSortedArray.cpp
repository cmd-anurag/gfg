#include<vector>
using std::vector;

class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          // code here
          int left = 0;
          int right = arr.size() - 1;

          while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == target) {
                return mid;
            }
            else if(mid - 1 >= 0 && arr[mid-1] == target) 
                return mid-1;
            else if(mid + 1 < arr.size() && arr[mid+1] == target) 
                return mid+1;
            else if(target > arr[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
          }

          return -1;
      }
  };