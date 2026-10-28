/*
我对这道题的解题思路就是复用之前的prefix tree；
对于.的状态，就是dfs往下搜，对于.的话每个子节点都搜一遍
*/

#include <bits/stdc++.h>

using namespace std;

class WordDictionary {
private:
    bool isEnd;
    vector<WordDictionary*> children;

public:
    WordDictionary() {
        this->isEnd = false;
        children = vector<WordDictionary*>(26, 0);
    }
    
    void addWord(string word) {
        WordDictionary* cur = this;
        
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) {
                cur->children[i] = new WordDictionary();
            }
            cur = cur->children[i];
        }

        cur->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(this, word, 0);
    }

    bool dfs(WordDictionary* cur, string& word, int index) {
        // reaching the end of the string
        if (index == word.size()) {
            return cur->isEnd;
        }

        char c = word[index];
        if (c == '.') {
            for (WordDictionary* next : cur->children) {
                if (next && dfs(next, word, index+1)) return true; 
            }
            return false;
        }
        
        WordDictionary* next = cur->children[c-'a'];
        return next && dfs(next, word, index+1);
    }
};