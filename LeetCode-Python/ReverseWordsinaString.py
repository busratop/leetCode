class Solution:
    def reverseWords(self, s: str) -> str:
        x = s.split()
        x_string = ' '.join(x[::-1])
        return x_string
