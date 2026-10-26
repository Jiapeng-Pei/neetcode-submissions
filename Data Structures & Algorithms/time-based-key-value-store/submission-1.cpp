/*
感觉这道题就是用一个binary search
首先针对每一个key都保存一个vector<pair<int, string>>这样的pair
然后每次调用get时都去这个数组里面拿time去搜索就可以
*/

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
    
    string binarySearch(vector<pair<int, string>>& values, int time) {
        if (!values.size()) return "";

        int left = 0, right = values.size() - 1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            int cur = values[mid].first;
            if (cur < time) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        if (values[left].first > time) {
            // case 1: previous exists, returns the previous value
            // case 2: previous not exist, return empty string
            return left == 0 ? "" : values[left - 1].second;
        }
        else {
            return values[left].second;
        }
    }

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        return binarySearch(mp[key], timestamp);
    }
};
