class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> charFreq(26, 0);
        int uniqueCharCounter = 0;

        for (char c : s1) {
            // first appearance, a new char
            if (++charFreq[c - 'a'] == 1) uniqueCharCounter++;
        }   

        int left, right;
        for (right = 0; right < s2.size(); right++) {
            left = right - s1.size();
            // we need to remove the left most char
            if (left >= 0) {
                char toRemove = s2[left];
                // only chars in S1 will have positive charFreq counter
                if (++charFreq[toRemove - 'a'] == 1) uniqueCharCounter++;
            }

            char toAdd = s2[right];
            // the substring has all of 1 char appearance
            if (--charFreq[toAdd - 'a'] == 0) uniqueCharCounter--;
            // all the chars are matched
            if (uniqueCharCounter == 0) return true; 
        }

        return false;
    }
};
