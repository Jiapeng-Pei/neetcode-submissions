/*
给定一个capacity 该如何计算需要几天把它ship完？把weights全遍历一遍 O(n)的时间复杂度
weights的上下界分别是什么？max(weights)和max(weights)
binary search的边界条件是什么？
calcualte the days it take it ship all of them;
if (days > days) {
}
else {
}
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;
        for (int w : weights) {
            left = max(left, w);
            right += w;
        }
        
        // todo
        while (left < right) {
            int mid = left + (right - left) / 2;
            int daysRequired = calcualteDays(weights, mid);
            // not enough time, need to increase the limit
            if (daysRequired > days) {
                left = mid + 1;
            }
            // current limit is safe. reset the limit
            else {
                right = mid;
            }
        } 

        return left;
    }

    int calcualteDays(vector<int>& weights, int limit) {
        // It takes at least 1 day to ship; The first days has the capacity as limit
        int ret = 1;
        int remains = limit;
        for (int w : weights) {
            if (remains < w) {
                ret++;
                remains = limit;
            }
            remains -= w;
        }

        return ret;
    }
};