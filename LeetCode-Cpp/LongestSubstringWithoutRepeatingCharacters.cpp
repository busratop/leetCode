class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        int count = 0;
        int char_count[256] = {0};

        for(int i=0, r = 0; r < l; r++){
            char_count[s[r]]++;
            while (char_count[s[r]] > 1) {
                char_count[s[i]]--;
                i++;
            }
            count = max(count, r - i + 1);
        }
        return count;
    }
};
