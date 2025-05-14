#include <string>
using std::string;

class Solution
{
public:
    string helper(string t)
    {
        int n = t.length();

        string output = "";

        for (int i = 0; i < n; i++)
        {
            char letter = t[i];
            int freq = 0;

            int j = i;
            for (; j < n && t[j] == letter; ++j)
            {
                ++freq;
            }
            i = j - 1;

            output += std::to_string(freq) + letter;
        }

        return output;
    }

    string countAndSay(int n)
    {
        if (n == 1)
            return "1";

        return helper(countAndSay(n - 1));
    }
};