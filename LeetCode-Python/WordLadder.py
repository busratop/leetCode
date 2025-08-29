class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        word_set = set(wordList)
        if endWord not in word_set:
            return 0
        
        queue = deque([(beginWord, 1)])  # (kelime, adım sayısı)
        
        while queue:
            word, length = queue.popleft()
            if word == endWord:
                return length
            
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    new_word = word[:i] + c + word[i+1:]
                    if new_word in word_set:
                        word_set.remove(new_word)  # tekrar ziyaret etme
                        queue.append((new_word, length + 1))
        
        return 0
