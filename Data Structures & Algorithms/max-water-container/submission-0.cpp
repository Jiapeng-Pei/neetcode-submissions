class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int result = 0;
        while (left < right) {
            int leftBar = heights[left];
            int rightBar = heights[right];
            result = max(result, min(leftBar, rightBar) * (right - left));
            if (leftBar <= rightBar) left++;
            else right--;
        }

        return result;
    }
};
