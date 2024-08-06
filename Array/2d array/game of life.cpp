class Solution {
public:
    int checkEightNeighbours(int n, int m, vector<vector<int>>& board, int i, int j) {
        int countOnes = 0;

        // Checking all 8 directions
        if (i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == 1) countOnes++;   // Top-left
        if (i-1 >= 0 && board[i-1][j] == 1) countOnes++;                   // Top
        if (i-1 >= 0 && j+1 < m && board[i-1][j+1] == 1) countOnes++;      // Top-right
        if (j-1 >= 0 && board[i][j-1] == 1) countOnes++;                   // Left
        if (j+1 < m && board[i][j+1] == 1) countOnes++;                    // Right
        if (i+1 < n && j-1 >= 0 && board[i+1][j-1] == 1) countOnes++;      // Bottom-left
        if (i+1 < n && board[i+1][j] == 1) countOnes++;                    // Bottom
        if (i+1 < n && j+1 < m && board[i+1][j+1] == 1) countOnes++;       // Bottom-right

        return countOnes;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> newBoard(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int countOnes = checkEightNeighbours(n, m, board, i, j);
                
                if (board[i][j] == 0) {
                    if (countOnes == 3) newBoard[i][j] = 1;  // Corrected assignment
                } else {
                    if (countOnes == 2 || countOnes == 3) newBoard[i][j] = 1;  // Corrected assignment
                }
            }
        }

        board = newBoard;
    }
};
