class Solution {
public:
    int maxRow(vector<vector<int>>& mat, int col) {
        int row = 0;
        for (int i = 1; i < mat.size(); i++) {
            if (mat[i][col] > mat[row][col])
                row = i;
        }
        return row;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), row = -1;
        int l = 0, h = m - 1; // choose col
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int row = maxRow(mat, mid); // up down element is small
            // check for left right now
            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;
            if (mat[row][mid] > left && mat[row][mid] > right)
                return {row, mid};
            if (mat[row][mid] < left)
                h = mid - 1;
            else if (mat[row][mid] < right)
                l = mid + 1;
        }
        return {-1, -1};
    }
};