class MedianFinder {
public:
    // Küçük sayıların tutulduğu max-heap
    // Varsayılan olarak std::priority_queue max-heap'tir.
    std::priority_queue<int> max_heap;

    // Büyük sayıların tutulduğu min-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    MedianFinder() {
        // Kurucu metodda özel bir başlangıç işlemi gerekmez.
    }
    
    void addNum(int num) {
        // Yeni sayıyı max_heap'e ekleyerek başla (küçük yarıya).
        max_heap.push(num);

        // max_heap'in en büyük elemanı (yani en üstteki) min_heap'in en küçük elemanından (yani en üstteki) büyükse
        // veya max_heap gereğinden büyükse, elemanları dengele.
        // max_heap.top() her zaman min_heap.top()'tan küçük veya eşit olmalı.
        // Eğer değilse, max_heap'in en büyüğünü min_heap'e taşı.
        if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        // Heap'lerin boyutlarını dengele:
        // max_heap, min_heap'e eşit veya bir eleman fazla olmalı.
        // Eğer max_heap çok küçükse (min_heap'ten az elemanı varsa), min_heap'ten max_heap'e taşı.
        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        // Eğer max_heap çok büyükse (min_heap'ten birden fazla elemanı varsa), max_heap'ten min_heap'e taşı.
        else if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        if (max_heap.empty()) {
            return 0.0; // Sayı eklenmediyse, medyan tanımsızdır veya 0.0 dönebiliriz.
        }

        // Toplam sayı tek ise, medyan max_heap'in en büyük elemanıdır.
        if (max_heap.size() > min_heap.size()) {
            return static_cast<double>(max_heap.top());
        } 
        // Toplam sayı çift ise, medyan iki heap'in en üstteki elemanlarının ortalamasıdır.
        else {
            return (static_cast<double>(max_heap.top()) + min_heap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
