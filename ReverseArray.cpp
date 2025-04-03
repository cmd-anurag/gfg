#include<bits/stdc++.h>

using namespace std;

class Solution {
     // pretty easy
    public:
      void reverseArray(vector<int> &arr) {
          // code here
          int left = 0;
          int right = arr.size()-1;
          
          while(left < right)
          {
              swap(arr[left++], arr[right--]);
          }
      }

      // Time Complexity - O(n);
      // Space Complexity - O(1);

      private:
      void swap(int &x, int &y) {
          int t = x;
          x = y;
          y = t;
      }
     
      
  };