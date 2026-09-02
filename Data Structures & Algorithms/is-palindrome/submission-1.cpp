class Solution {
public:
    bool isPalindrome(string s) {
        string strCleaned = "";
        for (char c : s) {
            char cCleaned = cleanChar(c);
            if (cCleaned != '!') strCleaned.push_back(cCleaned);
        }

        int left = 0, right = strCleaned.size() - 1;
        while (left < right) {
            if (strCleaned[left++] != strCleaned[right--]) return false; 
        }

        return true;
    }

private: 

    char cleanChar(char c) {
        bool isUpperLetter = c >= 'A' && c <= 'Z';
        bool isLowerLetter = c >= 'a' && c <= 'z';
        bool isNumber = c >= '0' && c <= '9';

        if (!isUpperLetter && !isLowerLetter && !isNumber) {
            return '!';
        }

        if (isUpperLetter) {
            return 'a' + c - 'A';
        }
        else {
            return c;
        }
    }
};
