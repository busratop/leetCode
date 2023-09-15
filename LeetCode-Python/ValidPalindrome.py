class Solution:
    def isPalindrome(self, s: str) -> bool:
        if s == " ": return True

        pattern = r'[^A-Za-z0-9]+'
        s = re.sub(pattern, '', s)
        s = s.lower()

        r = s[::-1]

        if r ==s : return True 
        else: return False