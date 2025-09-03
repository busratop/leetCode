class WordDictionary {
private:
    struct TrieNode {
        bool isEnd;  // bir kelimenin sonunu işaretler
        unordered_map<char, TrieNode*> children;
        TrieNode() : isEnd(false) {}
    };
    
    TrieNode* root;

    bool dfs(string &word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isEnd;  // kelimenin sonuna ulaştık mı?
        }
        
        char c = word[index];
        if (c == '.') {
            // '.' → tüm çocukları denemeliyiz
            for (auto &p : node->children) {
                if (dfs(word, index + 1, p.second)) {
                    return true;
                }
            }
            return false;
        } else {
            if (!node->children.count(c)) return false;
            return dfs(word, index + 1, node->children[c]);
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
