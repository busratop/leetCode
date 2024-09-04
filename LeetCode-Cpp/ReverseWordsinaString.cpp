class Solution {
public:
    string reverseWords(string s) {
        std::istringstream iss(s);
        std::vector<std::string> words;

        // Boşlukları kullanarak cümleyi kelimelere ayır
        std::string word;
        while (iss >> word) {
            words.push_back(word);
        }

        // Kelimelerin sırasını tersine çevir
        std::reverse(words.begin(), words.end());

        // Ters çevrilmiş kelimeleri tek bir boşluk ile birleştir
        std::ostringstream oss;
        for (const auto& w : words) {
            oss << w << ' ';
        }

        // Gereksiz sondaki boşluğu temizle ve sonucu döndür
        return oss.str().substr(0, oss.str().size() - 1);
        }
};
