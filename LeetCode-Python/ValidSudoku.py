class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    // Her satır için kontrol
    for (int i = 0; i < 9; ++i) {
        unordered_set<char> rowSet;
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                if (rowSet.find(board[i][j]) != rowSet.end()) {
                    return false;  // Geçersiz durum
                }
                rowSet.insert(board[i][j]);
            }
        }
    }

    // Her sütun için kontrol
    for (int j = 0; j < 9; ++j) {
        unordered_set<char> colSet;
        for (int i = 0; i < 9; ++i) {
            if (board[i][j] != '.') {
                if (colSet.find(board[i][j]) != colSet.end()) {
                    return false;  // Geçersiz durum
                }
                colSet.insert(board[i][j]);
            }
        }
    }

    // Her 3x3 alt kare için kontrol
    for (int block = 0; block < 9; ++block) {
        unordered_set<char> blockSet;
        for (int i = block / 3 * 3; i < block / 3 * 3 + 3; ++i) {
            for (int j = (block % 3) * 3; j < (block % 3) * 3 + 3; ++j) {
                if (board[i][j] != '.') {
                    if (blockSet.find(board[i][j]) != blockSet.end()) {
                        return false;  // Geçersiz durum
                    }
                    blockSet.insert(board[i][j]);
                }
            }
        }
    }

    return true;  // Geçerli durum
    }
};
