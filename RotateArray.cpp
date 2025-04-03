#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
  
      // Function to rotate an array by d elements in counter-clockwise direction.
      void rotateArr(vector<int>& arr, int d) {
          int n = arr.size();
          
          
          // one brute force way to solve this is by manually deleting first d elements and appending them to the last, that however takes extra time and space.
          // there is a more elegant and efficient solution
          
          int rotations = d % n;
          if(!rotations) return;
          
          reverseArray(arr, 0, rotations-1);
          reverseArray(arr, rotations, n-1);
          reverseArray(arr, 0, n-1);
          
          
          
          // code here
      }
      
      private:
          void reverseArray(vector<int> &arr, int left, int right) {
              int l = left;
              int r = right;
              
              while(l < r) {
                  int t = arr[l];
                  arr[l] = arr[r];
                  arr[r] = t;
                  ++l;
                  --r;
              }
          }
          
          
      
  };