class TrieNode:
    def __init__(self):
        self.children = {}   # harf → TrieNode
        self.isEnd = False   # kelimenin bitişini işaretler

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.isEnd = True

    def search(self, word: str) -> bool:
        def dfs(index: int, node: TrieNode) -> bool:
            if index == len(word):
                return node.isEnd
            c = word[index]
            if c == ".":
                # '.' → tüm çocukları dene
                for child in node.children.values():
                    if dfs(index + 1, child):
                        return True
                return False
            else:
                if c not in node.children:
                    return False
                return dfs(index + 1, node.children[c])
        
        return dfs(0, self.root)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
