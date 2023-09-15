class Solution {
public:
    bool isPalindrome(string s) {
        if (s == " ") return true;

       auto it = std::remove_if(s.begin(), s.end(), [](char const &c) {
        return !std::isalnum(c);
        });
        s.erase(it, s.end());

        string t = s;
        reverse(s.begin(), s.end()); 

        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c){ return std::tolower(c); });
        std::transform(t.begin(), t.end(), t.begin(),
            [](unsigned char c){ return std::tolower(c); });

        if (t == s) return true;
        else return false;

        

    }
};