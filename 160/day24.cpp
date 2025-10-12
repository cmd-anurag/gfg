#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b [0];
}

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end(), compare);
        vector<vector<int>> result;
        result.push_back({arr[0][0], arr[0][1]});

        for(int i = 1; i < arr.size(); ++i) {
            vector<int> interval = arr[i];
            vector<int> lastAddedInterval = result.back();
            
            if(interval[0] <= lastAddedInterval[1]) {
                
                result.back().at(1) = max(lastAddedInterval[1], interval[1]);

            } else {
                result.push_back(interval);
            }
        }
        return result;
    }
    
};


int main()
{
    vector<vector<int>> arr = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    Solution s;
    auto result = s.mergeOverlap(arr);
    for(auto pair : result) {
        cout << pair[0] << " -> " << pair[1] << '\n';
    }
}