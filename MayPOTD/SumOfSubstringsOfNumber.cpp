#include<string>
using std::string;

class Solution {
public:
    int sumSubstrings(string &s) {
        int n = s.size();
        int64_t sum = 0, f = 0;
        for (int i = 0; i < n; i++) {
            f = f * 10 + (s[i] - '0') * (i + 1);
            sum += f;
        }
        return (int)sum;
    }
};