class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         // C++'taki std::priority_queue varsayılan olarak bir max-heap'tir.
        // k'ıncı en büyük elemanı bulmak için, k kadar eleman barındıran
        // bir min-heap'e ihtiyacımız var.
        // std::greater<int> kullanarak bir min-heap oluştururuz.
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

        // Dizideki her eleman üzerinde döngü yap
        for (int num : nums) {
            // Mevcut elemanı min-heap'e ekle
            min_heap.push(num);

            // Eğer heap'in boyutu k'yi aşarsa,
            // heap'teki en küçük elemanı (yani en üstteki elemanı) çıkar.
            // Bu, heap'in her zaman k en büyük elemanı tutmasını sağlar.
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // Döngü tamamlandığında, min-heap'in tepesindeki eleman
        // k'ıncı en büyük eleman olacaktır.
        return min_heap.top();
    }
};
