class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int j = 0;
        int minlen = s.size() + 1; 
        unordered_map<char, int> mp;
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }
        int cnt = mp.size();
        int start = 0;

        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--; 
                if (mp[s[j]] == 0) {
                    cnt--;
                }
            }

            while (cnt == 0) {
                if (j - i + 1 < minlen) {
                    minlen = j - i + 1;
                    start = i;
                }

                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) {
                        cnt++;
                    }
                }
                i++;
            }

            j++;
        }

        return minlen == s.size() + 1 ? "" : s.substr(start, minlen);
    }
};
