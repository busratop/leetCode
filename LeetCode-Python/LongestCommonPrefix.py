class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        l = ""
        strs =sorted(strs)

        for i in range(min(len(strs[0]),len(strs[-1]))):
            if(strs[0][i]!=strs[-1][i]):
                break;

            l += strs[0][i];

        return l;
    