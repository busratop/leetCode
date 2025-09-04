class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None  # Tamamlanmış kelimeyi tutar

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        
        # Kelimeleri trie'a ekle
        for word in words:
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.word = word  # Kelime tamamlandığında kaydet

        rows, cols = len(board), len(board[0])
        result = []

        def dfs(r, c, node):
            char = board[r][c]
            if char not in node.children:
                return

            next_node = node.children[char]
            if next_node.word:
                result.append(next_node.word)
                next_node.word = None  # Aynı kelimeyi tekrar eklememek için

            board[r][c] = "#"  # Ziyaret edildi olarak işaretle

            for dr, dc in [(-1,0), (1,0), (0,-1), (0,1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] != "#":
                    dfs(nr, nc, next_node)

            board[r][c] = char  # Geri al (backtrack)

        # Tüm hücrelerden DFS başlat
        for r in range(rows):
            for c in range(cols):
                dfs(r, c, root)

        return result
