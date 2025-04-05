#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find the majority elements in the array
      vector<int> findMajority(vector<int>& arr) {
          // Your code goes here.
          
          
          // the extended boyer moore voting algo for 2 candidates


          int n = arr.size();
          
          int cand1 = 0;
          int cand2 = 0;
          int count1 = 0;
          int count2 = 0;
          
          for(int i : arr) {
              if(i == cand1) {
                  ++count1;
              }
              else if(i == cand2) {
                  ++count2;
              }
              else if(count1 == 0) {
                  cand1 = i;
                  count1 = 1;
              }
              else if(count2 == 0) {
                  cand2 = i;
                  count2 = 1;
              }
              else {
                  count1--;
                  count2--;
              }
          }
          
          count1 = 0;
          count2 = 0;
          
          for(int i : arr) {
              if(i == cand1) ++count1;
              else if(i == cand2) ++count2;
          }
          
          vector<int> result;
          if(count1 > n/3) {
              result.push_back(cand1);
          }
          if(count2 > n/3) {
              result.push_back(cand2);
          }
          sort(result.begin(), result.end());
          return result;
      }
  };