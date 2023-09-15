class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        found = haystack.find(needle)
        return found