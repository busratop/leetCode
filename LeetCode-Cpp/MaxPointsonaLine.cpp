class Solution {
public:
    // İki sayının en büyük ortak bölenini (GCD) hesaplayan yardımcı fonksiyon
    long long calculate_gcd(long long a, long long b) {
        return b == 0 ? a : calculate_gcd(b, a % b);
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        // 2 veya daha az nokta varsa, tüm noktalar aynı doğru üzerindedir.
        if (n <= 2) {
            return n;
        }

        int max_points_on_line = 0;

        // Her noktayı referans noktası olarak alıyoruz
        for (int i = 0; i < n; ++i) {
            // points[i] referans noktasına göre eğimlerin sayısını tutan bir harita
            // Anahtar: "dy/dx" stringi (basitleştirilmiş eğim), Değer: o eğime sahip nokta sayısı
            std::map<std::string, int> slope_counts;

            // points[i] ile aynı koordinatlara sahip noktaların sayısı
            // points[i] noktasının kendisi de bir kopya olarak sayılır (başlangıçta 1)
            int duplicates = 1;
            // points[i] ile aynı düşey çizgi üzerinde bulunan noktaların sayısı
            int vertical_points = 0;

            // Diğer tüm noktaları points[i] ile karşılaştırarak eğimleri hesaplıyoruz
            for (int j = i + 1; j < n; ++j) {
                long long x1 = points[i][0];
                long long y1 = points[i][1];
                long long x2 = points[j][0];
                long long y2 = points[j][1];

                // Eğer points[j], points[i] ile aynı koordinatlara sahipse (yinelenen nokta)
                if (x1 == x2 && y1 == y2) {
                    duplicates++;
                    continue; // Bu noktayı eğim hesaplamasına dahil etmiyoruz, sadece kopyaları artırıyoruz
                }

                long long dy = y2 - y1;
                long long dx = x2 - x1;

                if (dx == 0) { // Düşey çizgi (x koordinatları aynı)
                    vertical_points++;
                } else if (dy == 0) { // Yatay çizgi (y koordinatları aynı)
                    slope_counts["0/1"]++; // Yatay çizgiler için kanonik gösterim: 0/1
                } else {
                    // Eğimleri benzersiz bir anahtara dönüştürmek için normalize etme
                    // dx'i daima pozitif yapıyoruz. Eğer dx negatifse, hem dx hem dy'yi negate ederiz.
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    
                    // dy ve dx'in en büyük ortak bölenini bulup, eğimi basitleştiriyoruz
                    long long common_divisor = calculate_gcd(std::abs(dy), std::abs(dx));
                    dy /= common_divisor;
                    dx /= common_divisor;

                    // Basitleştirilmiş eğimi string anahtarı olarak kullanıyoruz
                    std::string key = std::to_string(dy) + "/" + std::to_string(dx);
                    slope_counts[key]++;
                }
            }

            // points[i] noktasından geçen ve en çok noktayı içeren çizgiyi bulma
            int current_max_for_i = vertical_points; // Düşey çizgilerdeki noktalarla başlıyoruz

            // Haritadaki tüm eğimler için en yüksek sayıyı bulma
            for (auto const& [slope_key, count] : slope_counts) {
                current_max_for_i = std::max(current_max_for_i, count);
            }
            
            // points[i] noktasından geçen en iyi doğru üzerindeki toplam nokta sayısı
            // = (en yüksek eğim/düşey çizgi üzerindeki distinct nokta sayısı) + (yinelenen noktalar)
            max_points_on_line = std::max(max_points_on_line, current_max_for_i + duplicates);
        }

        return max_points_on_line;
    }
};
