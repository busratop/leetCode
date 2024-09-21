class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,char>hash1,hash2;
        for(int i=0;i<s.length();i++)
        {
            if(hash1[s[i]]&& hash1[s[i]]!=t[i] )
            {
                return false;
            }
            if(hash2[t[i]]&& hash2[t[i]]!=s[i])
            {
                return false;
            }
            hash1[s[i]]=t[i];
            hash2[t[i]]=s[i];
        }
        return true;
    }
};
