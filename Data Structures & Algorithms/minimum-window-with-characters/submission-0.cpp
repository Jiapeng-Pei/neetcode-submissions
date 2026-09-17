class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        
        unordered_map<char, int> charFreq;
        int uniqueCharCount = 0;
        int resultLength = INT_MAX;
        for (char c : t) {
            charFreq[c]++;
            if (charFreq[c] == 1) uniqueCharCount++;
        }

        // the substring is represented as [left, right)
        int left = 0, right = 0;
        int resultIndex = -1;
        while (right < s.size()) {
            // expand the window until a substring is available
            while (uniqueCharCount > 0 && right < s.size()) {
                char toAdd = s[right++];
                charFreq[toAdd]--;
                if (charFreq[toAdd] == 0) uniqueCharCount--;     
            }

            // shortend the window until no longer available
            while (left < right && uniqueCharCount == 0) {
                if (right - left < resultLength) {
                    resultLength = right - left;
                    resultIndex = left;
                }

                char toRemove = s[left++];
                charFreq[toRemove]++;
                if (charFreq[toRemove] == 1) uniqueCharCount++;
            }
        }

        return resultIndex == -1 ? 
            "" :
            s.substr(resultIndex, resultLength);
    }
};
