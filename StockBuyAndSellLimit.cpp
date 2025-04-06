#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int maximumProfit(vector<int> &prices) {
          // code here
          

           int profit = 0;
           int maxProfit = 0;
           
           int minCP = prices[0];
           
           // simply track the minimum CP seen so far and calculate profit if sold on that day for each day
           for(int i : prices) {
               minCP = min(minCP, i);
               profit = i - minCP;
               maxProfit = max(maxProfit, profit);
           }
           
           return maxProfit;
          
      }
  };