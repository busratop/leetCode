class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
    
        // Set oluştur
        for (int num : nums) {
            numSet.insert(num);
        }
        
        int longestStreak = 0;
        
        // Her numarayı bir kez ziyaret et
        for (int num : numSet) {
            // Eğer numara dizideki başka bir diziden başka numaralardan daha küçükse, bu bir  dizinin başlangıcıdır
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
                
                // Ardışık sayıları kontrol et
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
                
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};
