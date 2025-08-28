class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
         // Start zaten geçerli; end genellikle bank'te olmalı (aksi halde ulaşılamaz)
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (startGene == endGene) return 0;
        if (!bankSet.count(endGene)) return -1;

        // BFS kurulumu
        queue<pair<string,int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);

        const string letters = "ACGT";

        while (!q.empty()) {
            auto [gene, steps] = q.front(); q.pop();

            // Her pozisyonda tek karakteri değiştirerek komşuları üret
            for (int i = 0; i < 8; ++i) {
                char original = gene[i];
                for (char c : letters) {
                    if (c == original) continue;
                    gene[i] = c;

                    if (gene == endGene) {
                        // endGene bank'te olduğuna göre bu geçerli bir adımdır
                        return steps + 1;
                    }

                    if (bankSet.count(gene) && !visited.count(gene)) {
                        visited.insert(gene);
                        q.push({gene, steps + 1});
                    }
                }
                gene[i] = original; // geri al
            }
        }
        return -1; // ulaşılamadı
    }
};
