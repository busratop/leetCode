class Solution {
public:
    bool isSubsequence(string s, string t) {
      int i = 0;
        for(int j = 0; j < t.size() && i < s.size(); j++){
            if(t[j] == s[i]) i++;
        }
        return i == s.size();
    }

};