#include <string>
#include <climits>

class Solution {
  public:
    bool safeToIncrease(int number, int ascii, bool isNegative)
    {
        if(isNegative)
        {
            return (number <= (INT_MAX - ascii + 49) / 10);
        }
        else
        {
            return (number <= (INT_MAX - ascii + 48) / 10);
        }
    }
    
    int myAtoi(std::string& s) {
        bool isNegative = false;
        bool firstDigitFound = false;
        bool charFlag = false;
        
        int answer = 0;

        for(char c : s)
        {
            if(!firstDigitFound)
            {
                if(c == ' '){
                    if(charFlag) return 0;
                    continue;
                }
                if(c == '0') {
                    charFlag = true;
                    continue;
                }
                
                
                if(c == '-') {
                    charFlag = true;
                    if(isNegative) return 0;
                    else {
                        isNegative = true;
                        continue;
                    }
                }

                int ascii = (int)c;
                
                if(ascii >= 48 && ascii <= 57) {
                    charFlag = true;
                    firstDigitFound = true;
                    answer = ascii - 48;
                }
                else {
                    return 0;
                }
            }
            else 
            {
                int ascii = (int)c;
                
                if(ascii >= 48 && ascii <= 57) {
                    if(safeToIncrease(answer, ascii, isNegative)) {
                        answer = (answer * 10) + (ascii - 48);
                    }
                    else {
                        return isNegative? INT_MIN : INT_MAX;
                    }
                }
                else {
                    return isNegative? -answer : answer;
                }
            }
        }
        return isNegative? -answer : answer;
    }
};