if (prices.empty()) return 0;

        int n = prices.size();
        vector<int> left(n, 0);  // 0..i arası en iyi işlem
        vector<int> right(n + 1, 0); // i..n-1 arası en iyi işlem

        // Soldan sağa: ilk işlem
        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i - 1], prices[i] - minPrice);
        }

        // Sağdan sola: ikinci işlem
        int maxPrice = prices[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(right[i + 1], maxPrice - prices[i]);
        }

        // İki işlemi birleştir
        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, left[i] + right[i + 1]);
        }

        return maxProfit;
