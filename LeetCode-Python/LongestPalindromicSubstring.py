class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""

        start, max_len = 0, 1
        n = len(s)

        def expand(left: int, right: int):
            nonlocal start, max_len
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
            length = right - left - 1
            if length > max_len:
                max_len = length
                start = left + 1

        for i in range(n):
            # Tek merkezli palindrome (örneğin "aba")
            expand(i, i)
            # Çift merkezli palindrome (örneğin "abba")
            expand(i, i + 1)

        return s[start:start + max_len]
