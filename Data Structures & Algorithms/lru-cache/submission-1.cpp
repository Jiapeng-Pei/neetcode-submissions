class LRUCache {
private:
    int capacity;
    list<pair<int,int>> nodeList;  // {key, value}，front = 最近使用
    unordered_map<int, list<pair<int,int>>::iterator> nodeMap;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = nodeMap.find(key);
        if (it == nodeMap.end()) return -1;
        nodeList.splice(nodeList.begin(), nodeList, it->second);  // 移到头部
        return it->second->second;  // it->second 是 list 迭代器，再 ->second 取 value
    }
    
    void put(int key, int value) {
        auto it = nodeMap.find(key);
        if (it != nodeMap.end()) {                 // key 已存在：更新值 + 移到头部
            it->second->second = value;
            nodeList.splice(nodeList.begin(), nodeList, it->second);
            return;
        }
        if ((int)nodeList.size() == capacity) {   // 满了：淘汰尾部
            nodeMap.erase(nodeList.back().first);
            nodeList.pop_back();
        }
        nodeList.emplace_front(key, value);        // 插到头部
        nodeMap[key] = nodeList.begin();
    }
};