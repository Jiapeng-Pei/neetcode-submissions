class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> charsArrayS(26, 0);
        vector<int> charsArrayT(26, 0);
        for (int i = 0; i < s.size(); i++) {
            char schar = s[i];
            char tchar = t[i];
            charsArrayS[schar-'a']++;
            charsArrayT[tchar-'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (charsArrayS[i] != charsArrayT[i]) return false;
        }

        return true;
    }
};
