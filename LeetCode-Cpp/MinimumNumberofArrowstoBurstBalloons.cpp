class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

    // Balonları uç noktalarına göre sırala
        sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    });

        int arrows = 1;
        int end = points[0][1];

        // Balonları kontrol et
        for (size_t i = 1; i < points.size(); ++i) {
            // Eğer mevcut balonun başlangıç noktası önceki balonun son noktasından büyükse, yeni bir ok atışı gerekir
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1]; // Son noktayı güncelle
            }
        }

        return arrows;
    }
};
