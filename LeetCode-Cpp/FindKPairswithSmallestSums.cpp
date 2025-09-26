#include <vector>
#include <queue> // std::priority_queue için
#include <utility> // std::pair için

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> result;

        // Kenar durumları kontrol et: diziler boşsa veya k sıfırsa boş bir liste döndür.
        if (nums1.empty() || nums2.empty() || k == 0) {
            return result;
        }

        // Min-heap oluştur:
        // Elemanlar (toplam, nums1_indeksi, nums2_indeksi) şeklinde saklanır.
        // C++'daki std::priority_queue varsayılan olarak max-heap'tir. Min-heap yapmak için
        // custom comparator veya std::greater kullanırız. Burada `pair<int, pair<int, int>>`
        // yapısını kullanıp, toplam değerine göre sıralanmasını sağlıyoruz.
        // `std::greater` ile en küçük toplamı en üste çıkaracak bir min-heap elde ederiz.
        std::priority_queue<std::pair<int, std::pair<int, int>>,
                            std::vector<std::pair<int, std::pair<int, int>>>,
                            std::greater<std::pair<int, std::pair<int, int>>>> min_heap;

        // Heap'i başlangıçta nums1'deki her elemanın nums2'deki ilk elemanıyla oluşturduğu çiftlerle doldur.
        // Sadece k veya nums1'in boyutu kadar çifti başlangıçta heape ekleriz, çünkü daha fazlasına ihtiyacımız yok.
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            // İlk çift: (nums1[i], nums2[0])
            min_heap.push({nums1[i] + nums2[0], {i, 0}});
        }

        // k adet en küçük çifti çıkar
        while (!min_heap.empty() && k > 0) {
            // Heap'ten en küçük toplamlı çifti çıkar
            auto top_element = min_heap.top();
            min_heap.pop();

            int current_sum = top_element.first;
            int i = top_element.second.first;  // nums1'deki indeks
            int j = top_element.second.second; // nums2'deki indeks
            
            // Çıkarılan çifti sonuca ekle
            result.push_back({nums1[i], nums2[j]});
            k--; // Kalan çift sayısını azalt

            // Eğer nums2'de geçerli nums1[i] için bir sonraki eleman varsa,
            // yeni çifti (nums1[i], nums2[j+1]) heape ekle.
            // Bu, her nums1 elemanı için nums2'deki tüm olası çiftleri sırayla keşfetmemizi sağlar.
            if (j + 1 < nums2.size()) {
                min_heap.push({nums1[i] + nums2[j+1], {i, j + 1}});
            }
        }
        
        return result;
    }
};
