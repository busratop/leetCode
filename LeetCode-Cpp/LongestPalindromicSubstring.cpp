class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 1;
        int n = s.size();

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // Döngüden çıkınca bir adım fazla gitmiş oluruz, bu yüzden 1 geri alıyoruz
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < n; i++) {
            // Tek merkezli palindrome (aba)
            expand(i, i);
            // Çift merkezli palindrome (abba)
            expand(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};
