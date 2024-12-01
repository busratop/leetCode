class LRUCache {
public:
int capacity; 
list<pair<int, int>> cacheList; 
unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
    LRUCache(int capacity) : capacity(capacity){
        
    }

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        } else {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); // Erişilen anahtarı listenin başına taşır
            return cacheMap[key]->second;
        }
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]); // Güncellenen anahtarı listenin başına taşır
            cacheMap[key]->second = value;
        } else {
            if (cacheList.size() == capacity) {
                cacheMap.erase(cacheList.back().first); // En az kullanılan anahtarı haritadan çıkarır
                cacheList.pop_back(); // En az kullanılan anahtarı listeden çıkarır
            }
            cacheList.emplace_front(key, value);
            cacheMap[key] = cacheList.begin();
        }
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
