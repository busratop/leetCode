class MedianFinder:

    def __init__(self):
        # min_heap: sayıların büyük yarısını tutar, en küçük eleman tepededir.
        #           (normal min-heap)
        self.min_heap = [] 
        
        # max_heap: sayıların küçük yarısını tutar, en büyük eleman tepededir.
        #           Sayıları negatif olarak saklayarak min-heap'i max-heap gibi kullanırız.
        self.max_heap = [] 
        

    def addNum(self, num: int) -> None:
        # Yeni sayıyı önce max_heap'e (küçük yarıya) ekle
        # max_heap'e -num ekleyerek bir max-heap gibi çalışmasını sağlarız.
        heapq.heappush(self.max_heap, -num)

        # max_heap'in en büyük elemanı (yani -max_heap[0]) min_heap'in en küçük elemanından
        # (yani min_heap[0]) büyükse, elemanları dengele.
        # Bu, max_heap'teki en büyük elemanın min_heap'teki en küçük elemandan küçük veya eşit olmasını sağlar.
        if self.min_heap and -self.max_heap[0] > self.min_heap[0]:
            val = -heapq.heappop(self.max_heap) # max_heap'ten en büyük elemanı al
            heapq.heappush(self.min_heap, val)  # min_heap'e ekle

        # Heap boyutlarını dengele:
        # max_heap, min_heap'e eşit veya bir eleman fazla olmalı.

        # Eğer max_heap çok büyükse (min_heap'ten birden fazla elemanı varsa), max_heap'ten min_heap'e taşı.
        if len(self.max_heap) > len(self.min_heap) + 1:
            val = -heapq.heappop(self.max_heap) # max_heap'ten en büyük elemanı al (negatif olduğu için en küçük indeksli)
            heapq.heappush(self.min_heap, val)  # min_heap'e ekle
        # Eğer min_heap çok büyükse (max_heap'ten fazla elemanı varsa), min_heap'ten max_heap'e taşı.
        elif len(self.min_heap) > len(self.max_heap):
            val = heapq.heappop(self.min_heap) # min_heap'ten en küçük elemanı al
            heapq.heappush(self.max_heap, -val) # max_heap'e negatifini ekle

    def findMedian(self) -> float:
        # Toplam sayı tek ise, medyan max_heap'in en büyük elemanıdır.
        # (max_heap her zaman eşit veya bir fazla elemana sahip olduğu için)
        if len(self.max_heap) > len(self.min_heap):
            return float(-self.max_heap[0]) # Negatif olarak saklandığı için tekrar negatife çevir
        # Toplam sayı çift ise, medyan iki heap'in en üstteki elemanlarının ortalamasıdır.
        else:
            if not self.max_heap: # Hiç sayı eklenmediyse
                return 0.0 # veya hata döndürülebilir
            return (-self.max_heap[0] + self.min_heap[0]) / 2.0


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
