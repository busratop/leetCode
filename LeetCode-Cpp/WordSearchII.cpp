class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word = "";
};


class Solution {
public:
 
        vector<string> result;
    int rows, cols;

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->word = word; // kelimeyi tamamladığımızda kaydet
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if (!node->children.count(c)) return;

        node = node->children[c];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // tekrar eklememek için temizle
        }

        board[i][j] = '#'; // ziyaret edildi olarak işaretle

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (auto [dx, dy] : directions) {
            int ni = i + dx, nj = j + dy;
            if (ni >= 0 && nj >= 0 && ni < rows && nj < cols && board[ni][nj] != '#') {
                dfs(board, ni, nj, node);
            }
        }

        board[i][j] = c; // geri al (backtrack)
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words)
            insertWord(root, word);

        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                dfs(board, i, j, root);

        return result;

    }
    
};
