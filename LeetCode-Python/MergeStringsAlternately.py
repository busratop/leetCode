class Solution:

    def mergeAlternately(word1, word2):

        length = max(len(word1),len(word2))
        merged = ""

        for x in range(length):
            if len(word1)>len(word2):
                merged += wor1[x]
            else:
                merged += word2[x]
        return merged
        
    mergeAlternately("word", "wort")


Solution.mergeAlternately("word", "wort")
