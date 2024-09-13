class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words:
            return []

        word_len = len(words[0])
        word_count = len(words)
        total_len = word_len * word_count
        word_dict = Counter(words)
        result = []

        for i in range(word_len):
            left, right = i, i
            current_dict = Counter()

            while right + word_len <= len(s):
                word = s[right:right + word_len]
                right += word_len
                current_dict[word] += 1

                while current_dict[word] > word_dict[word]:
                    current_dict[s[left:left + word_len]] -= 1
                    left += word_len

                if right - left == total_len:
                    result.append(left)

        return result


        
