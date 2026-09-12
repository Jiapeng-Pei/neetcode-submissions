/*
给定一个速度K，我应该如何计算出需要多久把香蕉吃完呢？时间复杂度是多少？O(n)
可以binary search k，下界是0，上节是max(piles)
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end());
        int left = 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int hours = hoursNeeded(piles, mid);
            
            // not enough time. Need to increase the speed.
            if (hours > h) {
                left = mid + 1;
            }
            // enough time. Keep this possible speed and reduce the window size.
            else {
                right = mid;
            }
        }

        return left;
    }

private: 
    int hoursNeeded(vector<int>& piles, int k) {
        int ret = 0;
        for (int n : piles) {
            ret += n / k;
            ret += n % k ? 1 : 0;
        }

        return ret;
    }
};
