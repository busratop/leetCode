class Solution:
    def findMaximizedCapital(self, k: int, w: int,  profits: List[int], capital: List[int]) -> int:
        n = len(profits)
        
        # Projeleri (sermaye, kar) çiftleri olarak saklayın
        # Python'da varsayılan olarak min-heap olduğu için kârı negatif olarak saklayacağız.
        projects = []
        for i in range(n):
            projects.append((capital[i], profits[i]))
            
        # Projeleri gereksinim duyulan sermayeye göre sıralayın
        projects.sort()
        
        # Mevcut sermayemizle yapabileceğimiz projelerin karlarını saklamak için Max-Heap
        # Python'ın heapq modülü min-heap'tir, bu yüzden kârları negatif olarak saklarız.
        max_heap_profits = [] 
        
        project_idx = 0 # Sıralanmış projeler listesindeki geçerli konum
        
        # K adet proje seçmeye çalışın
        for _ in range(k):
            # Mevcut sermaye 'w' ile yapabileceğimiz tüm projeleri heap'e ekleyin
            while project_idx < n and projects[project_idx][0] <= w:
                # Kârı negatif olarak ekleyerek max-heap mantığı uygula
                heapq.heappush(max_heap_profits, -projects[project_idx][1])
                project_idx += 1
            
            # Eğer heap boşsa, yapabileceğimiz başka proje yoktur, döngüyü bitiririz
            if not max_heap_profits:
                break
            
            # En yüksek kârlı projeyi seçin ve sermayemize ekleyin
            # Negatif değeri pozitife çevirerek kârı ekle
            w += -heapq.heappop(max_heap_profits)
            
        return w
