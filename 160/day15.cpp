#include<string>
using namespace std;

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        string answer;
        answer.reserve(1e6 + 2);
        
        int l1 = s1.size() - 1;
        int l2 = s2.size() - 1;
        
        bool carryFlag = false;
        
        while(l1 >= 0 && l2 >= 0)
        {
            
            if(s1[l1] == '0' && s2[l2] == '0')
            {
                if(carryFlag){
                    answer.push_back('1');
                }
                else {
                    answer.push_back('0');
                }
                carryFlag = false;
            }
            else if((s1[l1] == '0' && s2[l2] == '1') || (s1[l1] == '1' && s2[l2] == '0'))
            {
                if(carryFlag)
                {
                    answer.push_back('0');
                    carryFlag = true;
                }
                else {
                    answer.push_back('1');
                    carryFlag = false;
                }
            }
            else
            {
                if(carryFlag)
                {
                    answer.push_back('1');
                }
                else {
                    answer.push_back('0');
                }
                carryFlag = true;
            }
            
            --l1;
            --l2;
        }
        
        
        
        while(l1 >= 0)
        {
            if(carryFlag)
            {
                if(s1[l1] == '1') {
                    answer.push_back('0');
                    carryFlag = true;
                }
                else {
                    answer.push_back('1');
                    carryFlag = false;
                }
            }
            else {
                answer.push_back(s1[l1]);
            }
            l1--;
        }
        
        while(l2 >= 0)
        {
            if(carryFlag)
            {
                if(s2[l2] == '1') {
                    answer.push_back('0');
                    carryFlag = true;
                }
                else {
                    answer.push_back('1');
                    carryFlag = false;
                }
            }
            else {
                answer.push_back(s2[l2]);
            }
            l2--;
        }
        if(carryFlag) answer.push_back('1');
        
        int temp = answer.size() - 1;
        while(temp > 0 && answer[temp] == '0') {
            answer.pop_back();
            temp--;
        }
        
        reverse(answer);
        return answer;
        
    }
    private:
        void reverse(string &answer)
        {
            int left = 0;
            int right = answer.size() - 1;
            while(left < right)
            {
                std::swap(answer[left++], answer[right--]);
            }
        }
};