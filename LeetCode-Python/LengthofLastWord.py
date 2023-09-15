class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        if s[len(s)-1] == " ":
            s = s.strip()
            print(s)
        
        for l in range(len(s)-1, -1, -1):
            if s[l] == " ":
                break
            count +=1
                
        return count