#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
      void nextPermutation(vector<int>& arr) {
          int n = arr.size();
          
          // code here
          // Step 1. find the rightmost element smaller than its next element
          int pivot = -1;
          
          for(int i = n-2; i >= 0; --i)
          {
              if(arr[i] < arr[i+1]) {
                  pivot = i;
                  break;
              }
          }
          // If there is no pivot that means , the array is sorted in descending order
          // Next Greater Permutation would be the array sorted in ascending order
          if(pivot == -1) {
              reverseArray(arr, 0, n-1);
              return;
          }
          
          // Step 2 - find the rightmost element greater than pivot element
          int rightmostGreater = -1;
          for(int i = n-1; i >= 0; --i) {
              if(arr[i] > arr[pivot]) {
                  rightmostGreater = i;
                  break;
              }
          }
          
          // Step 3 - swap the pivot and rightmost greater element
          swap(arr[pivot], arr[rightmostGreater]);
          
          // Step 4 - reverse the section from pivot + 1 to end.
          reverseArray(arr, pivot + 1, n-1);
          
      }
      // Time Complexity - O(n)
      // Space Complexity - O(1)
      
      private:
        void reverseArray(vector<int> &arr, int start, int end) {
            while(start < end) {
                swap(arr[start++], arr[end--]);
            }
        }
        void swap(int &x, int &y) {
            int temp = x;
            x = y;
            y = temp;
        }
  };