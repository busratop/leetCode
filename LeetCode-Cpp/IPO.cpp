class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Projeleri {sermaye, kar} çiftleri olarak saklayın
        std::vector<std::pair<int, int>> projects(n);
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        
        // Projeleri gereksinim duyulan sermayeye göre sıralayın
        std::sort(projects.begin(), projects.end());
        
        // Mevcut sermayemizle yapabileceğimiz projelerin karlarını saklamak için Max-Heap
        std::priority_queue<int> max_heap_profits;
        
        int project_idx = 0; // Sıralanmış projeler listesindeki geçerli konum
        
        // K adet proje seçmeye çalışın
        for (int i = 0; i < k; ++i) {
            // Mevcut sermaye 'w' ile yapabileceğimiz tüm projeleri heap'e ekleyin
            while (project_idx < n && projects[project_idx].first <= w) {
                max_heap_profits.push(projects[project_idx].second);
                project_idx++;
            }
            
            // Eğer heap boşsa, yapabileceğimiz başka proje yoktur, döngüyü bitiririz
            if (max_heap_profits.empty()) {
                break;
            }
            
            // En yüksek kârlı projeyi seçin ve sermayemize ekleyin
            w += max_heap_profits.top();
            max_heap_profits.pop();
        }
        
        return w;
    }
};
