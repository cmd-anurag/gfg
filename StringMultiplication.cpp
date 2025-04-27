#include <string>
#include <vector>
using std::string, std::vector;

class Solution
{
public:
    /*You are required to complete below function */
    string multiplyStrings(string &s1, string &s2)
    {
        // Your code here
        if (s1 == "0" || s2 == "0")
            return "0";

        bool isPositive = true;
        if ((s1[0] == '-' && s2[0] != '-') || (s1[0] != '-' && s2[0] == '-'))
        {
            isPositive = false;
        }

        if (s1[0] == '-')
            s1 = s1.substr(1);
        if (s2[0] == '-')
            s2 = s2.substr(1);

        int n = s1.length();
        int m = s2.length();

        vector<int> result(n + m, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                int product = (s1[i] - '0') * (s2[j] - '0');
                int pos1 = i + j;
                int pos2 = i + j + 1;
                int sum = product + result[pos2];

                result[pos2] = sum % 10;
                result[pos1] += sum / 10;
            }
        }
        string output = "";
        for (int i = 0; i < result.size(); ++i)
        {
            if (!(output.empty() && result[i] == 0))
            {
                output += std::to_string(result[i]);
            }
        }
        if (output.empty())
            return "0";

        if (!isPositive)
        {
            output = '-' + output;
        }

        return output;
    }
};