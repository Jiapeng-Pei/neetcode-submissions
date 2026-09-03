// 思路：用"长度前缀 + 分隔符"编码每个字符串，避免因字符串内容含特殊字符而产生歧义。
// 编码时将每个字符串转为"长度#内容"的形式并依次拼接，例如 "Hello" 变为 "5#Hello"。
// 解码时先读取'#'之前的数字得到长度，再按该长度精确截取后面的字符，不断重复直到字符串结束。
// 2#ab4#antr

class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for (string& cur : strs) {
            int length = cur.size();
            encodedString += to_string(length);
            encodedString += '#';
            encodedString += cur;
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        int i = 0, j = 0;
        vector<string> result;
        while (i < s.size()) {
            while (isdigit(s[j])) j++;
            int length = stoi(s.substr(i, j-i));
            string curString = s.substr(j+1, length);
            result.push_back(curString);
            i = j = j + 1 + length;
        }

        return result;
    }
};
