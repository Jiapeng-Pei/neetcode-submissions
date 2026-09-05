/*
I have a feeling that this needs to use a mono-stack
for temps, I only care about the furture days where temp are higher.
like this case, the first '...X' elements represents the highest tmp of last day, which is X:
[...100, ... 101], we can just throw 100, it will get replaced, totally. No need to save it.
[...100 ... 95], we need to keep both 100 and 95, since 95 could be the highest tmp for weather between 100 and 95
So it is non-increasing stack. We also need to store the indexes.
So 2 scans. First to build the non-increasing stack with indexes.
Second scan to build the result.
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<pair<int, int>> nonIncreasingStack;
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {
            int curTemp = temperatures[i];
            while ( nonIncreasingStack.size() && curTemp > nonIncreasingStack.back().first ) {
                auto [_, j] = nonIncreasingStack.back();
                nonIncreasingStack.pop_back();
                result[j] = i - j;
            }
            nonIncreasingStack.push_back({curTemp, i});
        }

        return result;      
    }
};
