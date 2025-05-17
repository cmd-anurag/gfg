#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C)
    {
        // code here
        int n = arr.size();

        int left = 0;
        int right = n - 1;

        vector<int> result(n);
        int resultIndex = A >= 0? n-1 : 0;

        while(left <= right) {
            int leftValue = transform(arr[left], A, B, C);
            int rightValue = transform(arr[right], A, B, C);

            if(A >= 0) // upward parabola - largest values are towards the end and minimum value is somewhere in middle.
            {
                // build the result from right to left as result should be sorted in ascending and largest values are at right.
                if(leftValue > rightValue) {
                    result[resultIndex--] = leftValue;
                    ++left;
                }
                else {
                    result[resultIndex--] = rightValue;
                    --right;
                }

            }
            else // downward parabola - smallest values are towards the end and maximum value is somewhere in middle
            {
                // build the result from left to right as smallest values are at left
                if(leftValue < rightValue) {
                    result[resultIndex++] = leftValue;
                    ++left;
                }
                else {
                    result[resultIndex++] = rightValue;
                    --right;
                }
            }
        }

        return result;
        // this was interesting
    }

private:
    int transform(int x, int a, int b, int c) {
        return a*x*x + b*x + c;
    }

};