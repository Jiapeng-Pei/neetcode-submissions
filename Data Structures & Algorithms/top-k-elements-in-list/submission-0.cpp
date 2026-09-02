/*
We can use a map to count the occurance of every element in the array
Then we can use a priority queue of size K to only keep the top K most frequent elements
The space complexity is Log(K)
The time complexity is O(nlogk). This will work.

Another way is to use 
*/

#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> numFrequencyMap;
        // the first is frequence, the second is the number itself. 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minQueue;

        for (int n : nums) {
            numFrequencyMap[n]++;
        }

        for (auto it = numFrequencyMap.begin(); it != numFrequencyMap.end(); it++) {
            minQueue.push({it->second, it->first});
            if (minQueue.size() > k) minQueue.pop();
        }

        while (minQueue.size()) {
            auto [frequency, number] = minQueue.top();
            minQueue.pop();
            result.push_back(number);
        }
        
        return result;
    }
};
