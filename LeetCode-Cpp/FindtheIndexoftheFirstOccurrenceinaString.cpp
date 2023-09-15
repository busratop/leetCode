class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);
        if (found!=std::string::npos) return 0;
        else return -1;
    }
};