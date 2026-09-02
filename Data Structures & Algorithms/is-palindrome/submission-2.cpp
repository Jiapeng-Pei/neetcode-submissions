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
        if (!isalnum(c)) {
            return '!';
        }

        if (isupper(c)) {
            return tolower(c);
        }
        else {
            return c;
        }
    }
};
