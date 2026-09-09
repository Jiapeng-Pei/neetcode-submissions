class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // the actual row number, given that there are n elements for each row
            int i = mid / n;
            // the actual column number
            int j = mid - i * n;
            int cur = matrix[i][j];
            
            if (cur < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            } 
        }

        // the actual row number, given that there are n elements for each row
        int i = left / n;
        // the actual column number
        int j = left - i * n;
        return matrix[i][j] == target;
    }
};
