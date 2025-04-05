#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
      int maximumProfit(vector<int> &prices) {
          // code here

          //  just greedily sum all upward slopes 
          // since it is always profitable to buy low and sell high
          // multiple profitable small trades (prices[i] < prices[i+1]) equals the optimal larger trade

          int n = prices.size();
          int profit = 0;
          for(int i = 0; i < n-1; ++i) {
              if(prices[i] < prices[i+1]) {
                  profit += prices[i+1] - prices[i];
              }
          }
          return profit;
      }
  };