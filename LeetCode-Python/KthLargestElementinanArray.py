class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
          # Python'ın heapq modülü varsayılan olarak min-heap'tir.
        # Bu problem için doğrudan min-heap kullanabiliriz.
        
        # k kadar eleman barındıracak bir min-heap oluştur.
        min_heap = []

        # Dizideki her eleman üzerinde döngü yap
        for num in nums:
            # Mevcut elemanı min-heap'e ekle
            # heapq.heappush fonksiyonu elemanı ekler ve heap özelliğini korur.
            heapq.heappush(min_heap, num)

            # Eğer heap'in boyutu k'yi aşarsa,
            # heap'teki en küçük elemanı (yani en üstteki elemanı) çıkar.
            # heapq.heappop fonksiyonu en küçük elemanı çıkarır ve döndürür.
            # Bu, heap'in her zaman k en büyük elemanı tutmasını sağlar.
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        
        # Döngü tamamlandığında, min_heap'in tepesindeki eleman (yani en küçük eleman)
        # k'ıncı en büyük eleman olacaktır.
        # heapq.heappop kullanmak yerine, sadece en üstteki elemanı almak için min_heap[0] kullanabiliriz.
        return min_heap[0]
