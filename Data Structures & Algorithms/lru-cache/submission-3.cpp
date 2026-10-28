#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

class LRUCache {
private:
    int capacity;
    list<pii> cache;  // {key, value}，front = 最近使用
    unordered_map<int, list<pii>::iterator> nodeMap;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!nodeMap.count(key)) return -1;
        cache.splice(cache.begin(), cache, nodeMap[key]);
        return cache.front().second;
    }
    
    void put(int key, int value) {
        if (nodeMap.count(key)) {
            cache.splice(cache.begin(), cache, nodeMap[key]);
            cache.front().second = value;
            return;
        }

        if (cache.size() == capacity) {
            nodeMap.erase(cache.back().first);
            cache.pop_back();
        }

        cache.push_front({key, value});
        nodeMap[key] = cache.begin();
    }
};