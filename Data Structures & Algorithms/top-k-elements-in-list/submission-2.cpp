/*
关键观察：一个数字的出现频率，最大也不会超过数组长度n（比如数组长度为6，某个数最多出现6次）。

既然频率的取值范围被限定在[1, n]这个区间内（而不是任意大），我们可以反过来，用频率当"桶的下标"：

先用hashmap统计每个数字的频率：O(n)
创建一个大小为n+1的桶数组buckets，buckets[freq]存的是"所有出现频率恰好为freq的数字"（一个freq可能对应多个数字，比如nums=[1,1,2,2]里1和2的频率都是2）
遍历hashmap，把每个数字扔进对应频率的桶里：O(distinct elements) ≤ O(n)
从buckets[n]（频率最高的桶）往buckets[1]（频率最低的桶）方向遍历，依次把桶里的数字取出来，凑够k个就停：因为所有桶里数字总数不超过n，这一步最多也是O(n)
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> frequencyMap;
        vector<vector<int>> frequencyBucket(n+1);
        for (int num : nums) {
            frequencyMap[num]++;
        }

        for (auto [number, frequency] : frequencyMap) {
            frequencyBucket[frequency].push_back(number);
        }

        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            if (frequencyBucket[i].size()) {
                for (int num : frequencyBucket[i]) result.push_back(num);
            }
        }

        return result;
    }
};
