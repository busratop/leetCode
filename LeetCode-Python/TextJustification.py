class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        result = []
        current_line = []
        current_length = 0

        def justify_line(words, spaces, is_last_line):
            if is_last_line or len(words) == 1:
                return (' '.join(words)).ljust(maxWidth)
            else:
                extra_spaces = maxWidth - sum(len(word) for word in words)
                spaces_between_words = extra_spaces // (len(words) - 1)
                extra_spaces %= (len(words) - 1)

                justified_line = words[0]
                for i in range(1, len(words)):
                    spaces = spaces_between_words + (1 if i <= extra_spaces else 0)
                    justified_line += ' ' * spaces + words[i]

                return justified_line

        for word in words:
            if current_length + len(word) + len(current_line) > maxWidth:
                result.append(justify_line(current_line, maxWidth - current_length, False))
                current_line = []
                current_length = 0

            current_line.append(word)
            current_length += len(word)

        # Justify the last line (left-justified)
        result.append(justify_line(current_line, 1, True))

        return result


  
