class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 1; // Güvenlik: normalde verilere göre gerekmez.
        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_set<string> front{beginWord}, back{endWord};
        int length = 1;
        const int L = beginWord.size();

        while (!front.empty() && !back.empty()) {
            // Daha küçük sınırdan genişlet
            if (front.size() > back.size()) swap(front, back);

            unordered_set<string> next;
            for (const string& word : front) {
                string cur = word;
                for (int i = 0; i < L; ++i) {
                    char saved = cur[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == saved) continue;
                        cur[i] = c;

                        if (back.count(cur)) return length + 1; // İki uç buluştu

                        if (dict.count(cur)) {
                            next.insert(cur);
                            dict.erase(cur); // Ziyaret edildi olarak işaretle
                        }
                    }
                    cur[i] = saved;
                }
            }
            front.swap(next);
            ++length;
        }
        return 0;

    }
};
