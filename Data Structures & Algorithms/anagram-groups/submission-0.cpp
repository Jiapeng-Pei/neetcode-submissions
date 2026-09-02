class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for (int i = 0; i < strs.size(); i++) {
            string cur = strs[i];
            string curKey = "";
            vector<int> charsFrequency(26, 0);

            for (char c : cur) {
                charsFrequency[c-'a']++;
            }
            for (int freq : charsFrequency) {
                curKey += "#";
                curKey += to_string(freq);
            }

            mp[curKey].push_back(cur);
        }

        for (auto& [strKey, strArray] : mp) {
            result.push_back(strArray);
        } 

        return result;
    }
};
