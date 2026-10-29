/*
use a variable to track the longest distance I can reach and keep updating it
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0; // this is the index, it is inclusive
        int curIndex = 0;
        while (curIndex <= maxIndex && curIndex < nums.size()) {
            maxIndex = max(maxIndex, curIndex + nums[curIndex]);
            curIndex++;
        }

        return curIndex == nums.size();
    }
};
