class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> nextBoard(rows, vector<int>(cols, 0));

        auto countLiveNeighbors = [&](int row, int col) {
            int count = 0;
            int directions[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

            for (const auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && board[newRow][newCol] == 1) {
                    count++;
                }
            }

            return count;
        };

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int liveNeighbors = countLiveNeighbors(row, col);

                if (board[row][col] == 1) {  // Live cell
                    if (liveNeighbors < 2 || liveNeighbors > 3) {
                        nextBoard[row][col] = 0;  // Dies due to under-population or over-population
                    } else {
                        nextBoard[row][col] = 1;  // Lives on to the next generation
                    }
                } else {  // Dead cell
                    if (liveNeighbors == 3) {
                        nextBoard[row][col] = 1;  // Becomes a live cell due to reproduction
                    }
                }
            }
        }

        // Güncellenmiş tahtayı orijinal tahtaya kopyala
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                board[row][col] = nextBoard[row][col];
            }
        }
    }
};
