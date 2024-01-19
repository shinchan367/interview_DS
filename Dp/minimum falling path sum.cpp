class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<vector<int>> t(m,vector<int>(m));

        // Initialize the first row of the table
        for (int col = 0; col < m; col++) {
            t[0][col] = matrix[0][col];
        }

        // Fill the rest of the table using dynamic programming
        for (int row = 1; row < m; row++) {
            for (int col = 0; col < m; col++) {
                t[row][col] = matrix[row][col] + min({
                    t[row-1][col],
                    (col > 0) ? t[row-1][col-1] : INT_MAX,
                    (col < m-1) ? t[row-1][col+1] : INT_MAX
                });
            }
        }
