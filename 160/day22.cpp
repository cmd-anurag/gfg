#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();

        vector<int> freq(n+1, 0);
        
        int index = n;

        for(int i = 0; i < n; ++i) {
            if(citations[i] >= n) {

                freq[n]++;
            }  
            else {

                freq[citations[i]]++;
            } 
        }

        int sum = freq[n];

        while(sum < index)
        {
            --index;
            sum += freq[index];

        }
        return index;
    }
};

int main()
{
    Solution s;
    vector<int> citations = {6, 0, 3, 5, 3};
    cout << s.hIndex(citations) << '\n';
}