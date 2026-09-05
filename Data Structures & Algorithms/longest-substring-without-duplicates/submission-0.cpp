class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, result = 0;
        bool dup = false;
        unordered_map<char, int> charFrequencyMap;

        while (right < s.size()) {
            char curChar = s[right++];
            charFrequencyMap[curChar]++;
            
            if (charFrequencyMap[curChar] > 1) {
                dup = true;
            }

            while (dup) {
                char toRemove = s[left++];
                charFrequencyMap[toRemove]--;
                if (charFrequencyMap[toRemove] == 1) dup = false;
            }

            result = max(result, right - left);
        }

        return result;
    }
};
