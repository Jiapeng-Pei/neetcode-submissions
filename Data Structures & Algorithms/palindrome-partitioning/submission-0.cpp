/*
显然这道题是一个递归回溯的问题
recursive的条件应该怎么写呢 首先肯定有一个index，代表当前这个string遍历到哪儿了
在每一个state应该做什么呢
1. 找到下一个valid的对称字符串，把这个对称字符串放到结果里，然后进行下一次的遍历
如何返回呢
当遍历到最后并且所有substring都是对偶字符串 就停止 
*/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        recursive(s, 0);

        return result;
    }

private:
    vector<string> buffer;
    vector<vector<string>> result;

    void recursive(string s, int index) {
        if (index == s.size()) {
            result.push_back(buffer);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            int sz = i - index + 1;
            string curStr = s.substr(index, sz);
            if (isPalinfromeString(curStr)) {
                buffer.push_back(curStr);
                recursive(s, index + sz);
                buffer.pop_back();
            }
        }
    }

    bool isPalinfromeString(string s) {
        if (s.size() < 2) return true;
        for (int i = 0; i < s.size()-1-i; i++) {
            if (s[i] != s[s.size()-1-i]) return false;
        }

        return true;
    }
};
