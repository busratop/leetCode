class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        result = []
        
        # Kenar durumları kontrol et: diziler boşsa veya k sıfırsa boş bir liste döndür.
        if not nums1 or not nums2 or k == 0:
            return result

        # Min-heap, (toplam, nums1'deki indeks, nums2'deki indeks) şeklinde elemanları saklar.
        min_heap = [] 

        # Heap'i başlangıçta nums1'deki her elemanın nums2'deki ilk elemanıyla oluşturduğu çiftlerle doldur.
        # Sadece k veya len(nums1) kadar çifti başlangıçta heape ekleriz, çünkü k'dan fazla başlangıç elemanına ihtiyacımız yok.
        # Bu, daha büyük nums1 dizileri için performansı artırır.
        for i in range(min(len(nums1), k)):
            # İlk çift: (nums1[i], nums2[0])
            heapq.heappush(min_heap, (nums1[i] + nums2[0], i, 0))

        # k adet en küçük çifti çıkar
        while min_heap and k > 0:
            # Heap'ten en küçük toplamlı çifti çıkar
            current_sum, i, j = heapq.heappop(min_heap)
            
            # Çıkarılan çifti sonuca ekle
            result.append([nums1[i], nums2[j]])
            k -= 1 # Kalan çift sayısını azalt

            # Eğer nums2'de geçerli nums1[i] için bir sonraki eleman varsa,
            # yeni çifti (nums1[i], nums2[j+1]) heape ekle.
            # Bu, her nums1 elemanı için nums2'deki tüm olası çiftleri sırayla keşfetmemizi sağlar.
            if j + 1 < len(nums2):
                heapq.heappush(min_heap, (nums1[i] + nums2[j+1], i, j + 1))
        
        return result
