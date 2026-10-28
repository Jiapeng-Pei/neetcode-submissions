/*
感觉这道题就是使用树的数据结构 然后
*/
#include <bits/stdc++.h>

using namespace std;

class PrefixTree {
private:
    bool isEnd;
    unordered_map<char, PrefixTree*> children;

public:
    PrefixTree() {
        isEnd = false;
    }
    
    void insert(string word) {
        PrefixTree* cur = this;
        
        for (char c : word) {
            if (!cur->children[c]) {
                cur->children[c] = new PrefixTree();
            }
            cur = cur->children[c];
        }

        cur->isEnd = true;
    }
    
    bool search(string word) {
        PrefixTree* cur = this;
        
        for (char c : word) {
            if (!cur->children[c]) return false;
            cur = cur->children[c];
        }
        
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* cur = this;
        
        for (char c : prefix) {
            if (!cur->children[c]) return false;
            cur = cur->children[c];
        }
        
        return true;
    }
};
