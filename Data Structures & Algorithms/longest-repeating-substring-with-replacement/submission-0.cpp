/*
这道题还是用滑动窗口来做；这里的要求是换K个之后剩下的元素都是单一元素。
感觉需要维护当前窗口中最多的重复元素才可以；可以维护所有字符的数量，用O(1)的时间就可以算出来最多的元素；
或者，只有新进来的元素才有可能成为最高frequency的元素；只需要比较当前的最高frequecy与新进来的元素改变的frequency
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> charFrequency(26, 0);
        int ret = 0;
        int maxFreq = 0;
        int left = 0, right = 0;
        
        while (right < s.size()) {
            char toAdd = s[right++];
            charFrequency[toAdd - 'A']++;
            maxFreq = max(maxFreq, charFrequency[toAdd - 'A']);

            // the current string length is right - left; 
            // the longest possible string with 1 character is maxFreq + k
            while (maxFreq + k < right - left) {
                char toRemove = s[left++];
                charFrequency[toRemove - 'A']--;
                maxFreq = findMaxFreq(charFrequency);
            }

            ret = max(ret, right - left);
        }

        return ret;
    }

private:
    int findMaxFreq(vector<int>& charFrequency) {
        int ret = 0;
        for (int i : charFrequency) ret = max(ret, i);
        return ret;
    }
};
